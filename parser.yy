%reqiure "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%{
#include <iostream>
#include "decls.hpp"
%}

%token BOOL INT CELL
%token TRUE FALSE BOOL_UNDEF
%token EMPTY WALL BOX EXIT UNDEF
%token INF NEG_INF NAN

%token FORWARD
%token BACKWARD
%token LOAD
%token DROP
%token LOOK
%token TEST

%token<std::string> ID
%token<std::string> INT_VALUE
%token<std::string> BOOL_VALUE

%token SUM_UP_ARR

%token ASSIGNMENT

%token LESS GREATER EQUAL LEQ GEQ
%token IF THEN ELSE WHILE

%nterm<Statement* >
    arith_expr
    arith_val

%nterm<std::vector<Statement*>> statements program
%start program

%%

program: statements
        ;

statements: statement EOL { $$ = std::vector<Statement*>{$1}; }
           | statement EOL statements { $3.push_back($1); $$ = std::move($3); }
           ;

statement: spaces
          | params_decl
          | assignment
          | func_call
          | expr
          ;

params_decl: TYPE ID (',' ID)* { $$ = new ParamDecl{$1, $3}; }
            ;

assignment: bool_assign
          | int_assign
          | cell_assign
          ;

bool_assign: BOOL ID '=' BOOL_VALUE { $$ = new BoolAssign{$2, $4}; }
            ;

int_assign: INT ID '=' INT_VALUE { $$ = new IntAssign{$2, $4}; }
          ;

cell_assign: CELL ID '=' CELL_VALUE { $$ = new CellAssign{$2, $4}; }
           ;

func_call: FUNC_NAME '(' PARAM_DECL ')' { $$ = new FuncCall{$1, $3}; }
         ;

expr: arith_expr
    | log_expr
    ;

arith_expr: '-' arith_val
          | arith_val '+' arith_expr { $$ = new AddExpr{$1, $3} }
          | arith_val '-' arith_expr {}
          | SUM_UP_ARR { $$ = new SumUpArr{}; }
          ;

log_expr: log_val
        | comp_expr
        | xor_expr
        ;

comp_expr: arith_expr '<' '>' arith_expr { $$ = new CompExpr{$1, $3};  }
         ;

xor_expr: LOG_VAL '^' LOG_VAL { $$ = new XorExpr{$1, $3}; }
        ;

log_val: BOOL_VALUE
       | ID
       ;

arith_val: INT_VALUE { $$ = new IntValue {$1} }
         | ID        { $$ = new ID{$1}; }
         ;

