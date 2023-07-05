#include <fstream>
#include <iostream>

static int replaceString(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream ifs(filename);
    if (ifs.fail()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::ofstream ofs(filename + ".replace");
    if (ofs.fail()) {
        std::cerr << "Failed to create output file." << std::endl;
        ifs.close();
        return 1;
    }

    std::string input;
    int index;

    while (getline(ifs, input)) {
        while (!s1.empty() && input.find(s1) != std::string::npos) {
            index = input.find(s1);
            ofs << input.substr(0, index) << s2;
            input = input.substr(index + s1.size());
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
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }

    return replaceString(argv[1], argv[2], argv[3]);
}