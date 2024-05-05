#include "stmts.hpp"
#include "api_lab.hpp"
#include <vector>
#include <string>
#include <map>



struct Symtab {

    std::map<std::string, std::vector<Value>> data;
};


class Runtime {

public:
    Runtime(const AST &ast, const API_LAB &api_lab) : m_ast(ast), m_api_lab(api_lab) {};
    void exec() {
        /*for (stmt: m_ast.stmts) {
            exec_statement(stmt);
        }*/
    }

private:

    AST m_ast;
    API_LAB m_api_lab; 

    Symtab m_symtab;

    void exec_stmt(Statement *stmt) {
        switch (stmt->kind) {
            case StatementType::Assign:
                m_symtab.data[stmt->lhs->name].push_back(stmt->rhs->eval());
                /*Value val = eval_expr(stmt.right);
                if (stmt.left.is_array_element) {
                    m_symtab[stmt.left.name].set(stmt.left.i, val);
                } else {
                    m_symtab[stmt.left.name].set(val);
                }*/
            break;
            case StatementType::Expr: 
                //  do nothing
            break;
            case StatementType::Func: 

            break;
            case StatementType::CntlFlow:

            break;
            case StatementType::Operator:
                dynamic_cast<OperStmt*>(stmt)->act(m_api_lab.get_api());
            break;
        }
    }

};

