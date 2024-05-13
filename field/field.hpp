#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>


enum class CellType {
    EMPTY,
    WALL,
    EXIT
};

class Field {

std::size_t m_width = 8;
std::size_t m_height = 6;

public:

    auto width() { return m_width; }
    auto height() { return m_height; }

    Field() : data(m_width, std::vector<CellType>(m_height, CellType::EMPTY)) {}

    void get_field(std::ifstream &file); 

    void print_field();

    std::vector<std::vector<CellType>> data;
};


enum class Orient {
  North,
  East,
  South,
  West
};


class RobotPos {
    struct Pos { int x; int y; } cur_pos;
    Orient m_orient;

public:
    auto &orient() { return m_orient; }
    auto &x() { return cur_pos.x; }
    auto &y() { return cur_pos.y; }
};


