#include "stmts.hpp"
#include <fstream>

class API_LAB {

FnTable api;

public:
    API_LAB(std::ifstream &&ifs) {};
    const FnTable& get_api() { return api; }
};