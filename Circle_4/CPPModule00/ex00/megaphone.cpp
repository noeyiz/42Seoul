#include <iostream>

static void printUpperCase(std::string str) {
    int size = str.size();

    for (int i = 0; i < size; i++) {
        if (std::islower(str[i]))
            std::cout << static_cast<char>(std::toupper(str[i]));
        else
            std::cout << str[i];
    }
}

int main(int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        for (int i = 1; i < argc; i++)
            printUpperCase(argv[i]);
    std::cout << std::endl;

    return 0;
}
