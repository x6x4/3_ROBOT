


#include <fstream>
int main() {
    std::fstream programm;
    
    AST ast = parse(programm); 

    std::fstream labyrinth;

    API_Labyirinth api_lab(labyrinth);

    Runtime runtime(ast, api_lab);

    runtime.execute();
}