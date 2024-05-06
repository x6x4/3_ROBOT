%reqiure "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%{
#include <string>
#include "stmts.hpp"

%}

%union {
  std::string str;
  Statement* stmt;
  std::vector<Statement*> stmts;
}

%token BOOL
%token INT 
%token CELL
%token VAR

%token TRUE FALSE BOOL_UNDEF
%token EMPTY WALL BOX EXIT UNDEF
%token INF NEG_INF NAN

%token FORWARD BACKWARD LOAD DROP LOOK TEST LEFT RIGHT


%token spaces
%token<str> ID
%token<str> INT_VALUE
%token<str> BOOL_VALUE
%token<str> CELL_VALUE

%token SUM_UP_ARR

%token ASSIGN
%token FUNC
%token<str> FUNC_NAME
%token DO 
%token DONE
%token RETURN 

%token ENTRYPOINT

%token LESS GREATER EQUAL 
%token IF ELUND ELDEF WHILE FINISH

%type<stmt>
    arith_expr
    arith_val
    log_val
    var_decl
    bool_assign
    int_assign
    cell_assign
    func_call
    comp_expr
    xor_expr
    func_def
    main_def

%type<stmts> statements program
%start program

%%

program: main_def;

type:    BOOL | INT | CELL | VAR
LOG_VAL: TRUE | FALSE | BOOL_UNDEF

statements: statement '\n' { $$ = std::vector<Statement*>{$1}; }
           | statement '\n' statements { $3.push_back($1); $$ = std::move($3); }
           ;

statement: spaces
          | var_decl
          | assignment
          | func_call
          | expr
          | RETURN
          ;

var_decl: type ID { $$ = new VarDecl{$1, $2}; }
            ;

assignment: bool_assign
          | int_assign
          | cell_assign
          ;

bool_assign: BOOL ID ASSIGN BOOL_VALUE { $$ = new BoolAssign{$2, $4}; }
            ;

int_assign: INT ID ASSIGN INT_VALUE { $$ = new IntAssign{$2, $4}; }
          ;

cell_assign: CELL ID ASSIGN CELL_VALUE { $$ = new CellAssign{$2, $4}; }
           ;

main_def:  FUNC ENTRYPOINT DO statements DONE   { $$ = new FuncDef{$2}; }
func_def:  FUNC FUNC_NAME DO statements DONE    { $$ = new FuncDef{$2}; }

func_call: ID '(' ID ')' { $$ = new FuncCall{$1, $3}; }
         ;

cond_expr: IF log_expr DO statements DONE |
           IF log_expr DO statements DONE ELDEF DO statements DONE |
           IF log_expr DO statements DONE ELUND DO statements DONE |
           IF log_expr DO statements DONE ELDEF DO statements DONE ELUND DO statements DONE

while_loop:  WHILE log_expr DO statements DONE |
             WHILE log_expr DO statements FINISH statements DONE

expr: arith_expr
    | log_expr
    ;

arith_expr: '-' arith_val
          | arith_val '+' arith_expr { $$ = new AddExpr{$1, $3} }
          | arith_val '-' arith_expr { $$ = new SubsExpr{$1, $3}}
          | SUM_UP_ARR ID { $$ = new SumUpArr{$2}; }
          ;

log_expr: log_val
        | comp_expr
        | xor_expr
        ;

comp_expr: arith_expr LESS arith_expr { $$ = new CompExpr{$1, $3};  }
         | arith_expr GREATER arith_expr { $$ = new CompExpr{$1, $3};  }
         | arith_expr EQUAL arith_expr { $$ = new CompExpr{$1, $3};  }
         ;

xor_expr: LOG_VAL '^' LOG_VAL { $$ = new XorExpr{$1, $3}; }
        ;

log_val: BOOL_VALUE { $$ = new BoolValue {$1} }
       | ID         { $$ = new ID{$1}; }
       ;

arith_val: INT_VALUE { $$ = new IntValue {$1} }
         | ID        { $$ = new ID{$1}; }
         ;

