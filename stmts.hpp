#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include "types.hpp"

#include <cstddef>
#include <functional>
#include <map>
#include <unordered_map>
#include <vector>

class Field;
class RobotPos;

using OperSubr = std::function<void(Field& field, RobotPos &rob_pos)>;
using FnTable = std::unordered_map<OperType, OperSubr>;

class OperStmt : public Statement {
    OperType oper;

public: 
    void act(const FnTable& fn_table, Field& field, RobotPos &rob_pos) {
        fn_table.at(oper)(field, rob_pos);
    }
};

class VarDeclStmt : public Statement {
    //AssignType assignType;
};

class AssignStmt : public Statement {
    AssignType assignType;
};

class ExprStmt : public Statement {
    ExprType exprType;
};

class FnStmt : public Statement {
    FuncType funcType;
};



class BoolAssign : public AssignStmt {
public:

};

class IntAssign : public AssignStmt {

};

class CellAssign : public AssignStmt {
public:

};



class AddExpr : public ExprStmt {
public:
    
};

class CompExpr : public ExprStmt {

};

class XorExpr : public ExprStmt {
public:
    Value eval() override { 
        return std::get<Bool>(lhs->eval()) ^ std::get<Bool>(rhs->eval());
    }
};


class VarDecl : public FnStmt {

};

class FuncCall : public FnStmt {

};


class IntValue : public Statement {
public:
  IntValue(const std::string &val) : val(val) {}
  const std::string &get_val() const { return val; }

private:
  std::string val;
};

class ID : public Statement {
public:
  ID(const std::string &id) : id(id) {}
  const std::string &get_id() const { return id; }

private:
  std::string id;
};

class SumUpArr : public Statement {};

class AST {
    Statement* root;

public:
    AST(std::ifstream &&prog) {}
};

#endif  // _PARSER_HPP_