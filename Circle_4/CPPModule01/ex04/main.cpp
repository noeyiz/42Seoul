#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream ifs(filename);
    if (ifs.fail()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string contents;
    std::string line;

    while (getline(ifs, line)) {
        contents += line;
        if (!ifs.eof()) contents += "\n";
    }

    ifs.close();

    std::ofstream ofs(filename + ".replace");
    if (ofs.fail()) {
        std::cerr << "Failed to create output file." << std::endl;
        return 1;
    }

    size_t pos;
    while (!s1.empty() && contents.find(s1) != std::string::npos) {
        pos = contents.find(s1);
        ofs << contents.substr(0, pos) << s2;
        contents = contents.substr(pos + s1.size());
    }
    ofs << contents;
    if (s1.empty()) ofs << s2;

    ofs.close();

    return 0;
}