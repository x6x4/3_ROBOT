#include "../stmts.hpp"
#include "../api_lab.hpp"


class MY_API : public API_LAB {

public:

    MY_API(std::ifstream &&ifs) : API_LAB(ifs) {};

    void forward(Field& field, RobotPos &rob_pos) override;
    void backward(Field& field, RobotPos &rob_pos) override;
    void left_rot(Field& field, RobotPos &rob_pos) override;
    void right_rot(Field& field, RobotPos &rob_pos) override;
};


