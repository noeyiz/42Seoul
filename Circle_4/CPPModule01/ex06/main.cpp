#include "./Harl.hpp"

/*
    KEYWORD: switch문의 사용
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "invalid arguments ..." << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.complain(argv[1]);

    return 0;
}