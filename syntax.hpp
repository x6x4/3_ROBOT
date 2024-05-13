
enum class StatementType{
    Operator,
    VarDecl, 
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
    LEFT, 
    RIGHT,
    LOAD,
    DROP,
    LOOK,
    TEST
};

