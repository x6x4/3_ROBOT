class Symtab {
    std::map<std::string, std::vector<Value>>;
}

class Runtime {

    AST m_ast;
    API_LAbyrin m_lab; 

    Symtab m_symtab;

    void execute() {
        for stmt: m_ast.stmts {
            execute_statement(stmt);
        }
    }

    void execute_stmt(Statement stmt) {
        switch (stmt.kind) {
            case Assign:
                Value val = eval_expr(stmt.rigth);
                if left.is_array_element {
                    m_symtab[stmt.left.name].set(stmt.left.i, val);
                } else {
                    m_symtab[stmt.left.name].set(val);
                }
            break;
        
        }
    }
    
    Value eval_expt(Node* node) {
        switch (node.kind) {
            case Forward:
                return m_lab.forward()
        }
    }

};

