
#include "field.hpp"

void Field::get_field(std::ifstream &file) {
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            int cell_type;
            file >> cell_type;

            switch (cell_type) {
                case 0:
                    data[i][j] = CellType::EMPTY;
                    break;
                case 1:
                    data[i][j] = CellType::WALL;
                    break;
                case 2:
                    data[i][j] = CellType::EXIT;
                    break;
                default:
                    throw std::runtime_error("Invalid cell type");
            }
        }
    }

    file.close();
}


void Field::print_field() {
    for (const std::vector<CellType>& row : data) {
        for (CellType cell : row) {
            switch (cell) {
                case CellType::EMPTY:
                    std::cout << "0";
                    break;
                case CellType::WALL:
                    std::cout << "1";
                    break;
                case CellType::EXIT:
                    std::cout << "2";
                    break;
            }
        }
        std::cout << std::endl;
    }
}