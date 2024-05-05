#include <fstream>
#include "decls.hpp"
#include "runtime.hpp"

int main() {
    
    AST ast(std::ifstream("lab_exit.txt")); 

    std::fstream labyrinth;

    API_LAB apilab(std::ifstream("lab.lb"));

    Runtime runtime(ast, apilab);

    runtime.exec();
}