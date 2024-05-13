#pragma once

#include "stmts.hpp"
#include <fstream>
#include "field/field.hpp"

class API_LAB {

FnTable api = {
    {OperType::FORWARD, [this](Field& field, RobotPos &rob_pos) { API_LAB::forward(field, rob_pos); }},
    {OperType::BACKWARD, [this](Field& field, RobotPos &rob_pos) { API_LAB::backward(field, rob_pos); }},
    {OperType::LEFT, [this](Field& field, RobotPos &rob_pos) { API_LAB::left_rot(field, rob_pos); }},
    {OperType::RIGHT, [this](Field& field, RobotPos &rob_pos) { API_LAB::right_rot(field, rob_pos); }}
};

    Field lab_field; 

public:
    API_LAB(std::ifstream &ifs) {
        lab_field.get_field(ifs);
    };
    
    const FnTable& get_api() { return api; }

    virtual void forward(Field& field, RobotPos &rob_pos) {};
    virtual void backward(Field& field, RobotPos &rob_pos) {};
    virtual void left_rot(Field& field, RobotPos &rob_pos) {};
    virtual void right_rot(Field& field, RobotPos &rob_pos) {};
};