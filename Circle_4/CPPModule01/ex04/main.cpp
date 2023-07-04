#include <fstream>
#include <iostream>

void replaceString(std::string filename, std::string s1, std::string s2) {
    std::ifstream ifs;
    std::ofstream ofs;

    ifs.open(filename, std::ifstream::in);
    ofs.open(filename + ".replace");
    if (ifs.fail() || ofs.fail()) {
        std::cerr << "file open failed ..." << std::endl;
        return;
    }

    std::string input;
    int index;

    while (getline(ifs, input)) {
        if (input.find(s1) != std::string::npos) {
            index = input.find(s1);
            ofs << input.substr(0, index) << s2;
            input = input.substr(index + s1.size(), input.size() - index - s1.size());
        }
        ofs << input << std::endl;
    }
}

/*
    KEYWORD: 파일 입출력

    1. fstream 객체는 객체가 소멸될 때 자동으로 닫히지만, 명시적으로 표현도 가능
    2. 파일에 데이터를 쓸 때는 << 연산자 사용
    3. 파일에서 데이터를 읽을 때는 getline() 함수 사용
*/

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "invalid argument ..." << std::endl;
        return 1;
    }
    replaceString(argv[1], argv[2], argv[3]);
    return 0;
}