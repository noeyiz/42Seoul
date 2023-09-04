#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3001) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    argv = &argv[1];
    PmergeMe::sort(argc - 1, argv);
    return 0;
}