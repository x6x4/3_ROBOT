#include <fstream>
#include "runtime.hpp"
#include "my_api/my_api.hpp"


int main() {
    
    AST ast(std::ifstream("lab_exit.txt")); 

    std::fstream labyrinth;

    MY_API apilab(std::ifstream("lab.lb"));

    Runtime runtime(ast, apilab);

    runtime.exec();
}