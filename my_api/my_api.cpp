#include "my_api.hpp"


void MY_API::forward(Field& field, RobotPos &rob_pos) {
    switch (rob_pos.orient()) {
        case Orient::North:
        if (rob_pos.y() > 0 && field.data[rob_pos.y() - 1][rob_pos.x()] != CellType::WALL) {
            rob_pos.y()--;
        }
        break;
        case Orient::East:
        if (rob_pos.x() < field.width() - 1 && field.data[rob_pos.y()][rob_pos.x() + 1] != CellType::WALL) {
            rob_pos.x()++;
        }
        break;
        case Orient::South:
        if (rob_pos.y() < field.height() - 1 && field.data[rob_pos.y() + 1][rob_pos.x()] != CellType::WALL) {
            rob_pos.y()++;
        }
        break;
        case Orient::West:
        if (rob_pos.x() > 0 && field.data[rob_pos.y()][rob_pos.x() - 1] != CellType::WALL) {
            rob_pos.x()--;
        }
        break;
    }
}

void MY_API::backward(Field& field, RobotPos &rob_pos) {
    switch (rob_pos.orient()) {
        case Orient::North:
        if (rob_pos.y() < field.height() - 1 && field.data[rob_pos.y() + 1][rob_pos.x()] != CellType::WALL) {
            rob_pos.y()++;
        }
        break;
        case Orient::East:
        if (rob_pos.x() > 0 && field.data[rob_pos.y()][rob_pos.x() - 1] != CellType::WALL) {
            rob_pos.x()--;
        }
        break;
        case Orient::South:
        if (rob_pos.y() > 0 && field.data[rob_pos.y() - 1][rob_pos.x()] != CellType::WALL) {
            rob_pos.y()--;
        }
        break;
        case Orient::West:
        if (rob_pos.x() < field.width() - 1 && field.data[rob_pos.y()][rob_pos.x() + 1] != CellType::WALL) {
            rob_pos.x()++;
        }
        break;
    }
}

void MY_API::left_rot(Field& field, RobotPos &rob_pos) {
    switch (rob_pos.orient()) {
        case Orient::North:
        rob_pos.orient() = Orient::West;
        break;
        case Orient::East:
        rob_pos.orient() = Orient::North;
        break;
        case Orient::South:
        rob_pos.orient() = Orient::East;
        break;
        case Orient::West:
        rob_pos.orient() = Orient::South;
        break;
    }
}

void MY_API::right_rot(Field& field, RobotPos &rob_pos) {
    switch (rob_pos.orient()) {
        case Orient::North:
        rob_pos.orient() = Orient::East;
        break;
        case Orient::East:
        rob_pos.orient() = Orient::South;
        break;
        case Orient::South:
        rob_pos.orient() = Orient::West;
        break;
        case Orient::West:
        rob_pos.orient() = Orient::North;
        break;
    }
}