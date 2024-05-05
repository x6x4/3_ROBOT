
enum class StatementType{
    Operator,
    Assign,
    Expr,
    CntlFlow,
    Func
};


enum class FuncType {
    FuncCall,
    ParamDecl
};

enum class AssignType {
    BoolAssign,
    IntAssign,
    CellAssign
};

enum class ExprType {
    AddExpr,
    CompExpr,
    XorExpr
};

enum class OperType {
    FORWARD,
    BACKWARD,
    LOAD,
    DROP,
    LOOK,
    TEST
};

