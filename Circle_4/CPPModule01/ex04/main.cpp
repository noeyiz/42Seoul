#include <fstream>
#include <iostream>

static int replaceString(std::string filename, std::string s1, std::string s2) {
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open(filename);
    if (ifs.fail()) {
        std::cerr << "file open failed ..." << std::endl;
        return 1;
    }

    ofs.open(filename + ".replace");
    if (ofs.fail()) {
        std::cerr << "file create failed ..." << std::endl;
        ifs.close();
        return 1;
    }

    std::string input;
    int index;

    while (getline(ifs, input)) {
        while (input.find(s1) != std::string::npos) {
            index = input.find(s1);
            ofs << input.substr(0, index) << s2;
            input = input.substr(index + s1.size(), input.size() - index - s1.size());
        }
        ofs << input;
        if (ifs.eof() == false) ofs << std::endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "invalid argument ..." << std::endl;
        return 1;
    }
    return replaceString(argv[1], argv[2], argv[3]);
}