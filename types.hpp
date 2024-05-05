#include "syntax.hpp"
#include <variant>
#include <string>


class Bool;
class Cell;

using Value = std::variant<Bool, int, Cell>;

class Statement {
public:
    StatementType kind;
    Statement *rhs;
    Statement *lhs;
    
    virtual Value eval();
    const std::string name;
};



enum class BoolValue {
    TRUE, 
    FALSE,
    UNDEF
};

class Bool : public Statement {
    BoolValue value;

public:
    Bool (BoolValue val) : value(val) {};

    Bool operator^(const Bool& other) const {
        switch (value) {
            case BoolValue::TRUE:
                return other.value == BoolValue::FALSE ? Bool(BoolValue::TRUE) : Bool(BoolValue::FALSE);
            case BoolValue::FALSE:
                return other.value == BoolValue::TRUE ? Bool(BoolValue::TRUE) : Bool(BoolValue::FALSE);
            case BoolValue::UNDEF:
                return Bool(BoolValue::UNDEF);
        }
    }    
};




enum class CellValue {
    EMPTY, 
    WALL, 
    BOX, 
    EXIT,
    UNDEF
};

class Cell : public Statement {
    CellValue value;

public: 
    Value eval () {
        switch (value) {
            case CellValue::EXIT:
            case CellValue::EMPTY:
                return BoolValue::TRUE;
            
            case CellValue::BOX:
            case CellValue::WALL:
                return BoolValue::FALSE;
            
            case CellValue::UNDEF:
                return BoolValue::UNDEF;
        }
    }
};