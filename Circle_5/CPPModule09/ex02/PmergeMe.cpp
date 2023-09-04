#include "PmergeMe.hpp"

std::deque<int> PmergeMe::deque;

int getJacobsthalNum(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthalNum(n - 1) + 2 * getJacobsthalNum(n - 2);
}

void PmergeMe::parseInput_D(int size, char *input[]) {
    int num; char c;
    for (int i = 0; i < size; i++) {
        std::istringstream ss(input[i]);
        if ((ss >> num) == false || ss >> c
        || num <= 0 || num != std::atoi(input[i]))
            throw BadInputException();
        deque.push_back(num);
    }
}

void PmergeMe::checkValid_D() {
    std::deque<int> temp;
    for (size_t i = 0; i < deque.size(); i++) temp.push_back(deque[i]);
    // check already sorted
    bool sorted = true;
    for (size_t i = 0; i < deque.size() - 1; i++) {
        if (temp[i] > temp[i + 1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) throw AlreadySortedException();
    // check duplication
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0; i < deque.size() - 1; i++)
        if (temp[i] == temp[i + 1]) throw DuplicateValueException();
}

void PmergeMe::mergeInsertionSort_D() {
    // 0. 홀수일 때 마지막 수 저장해두기
    int stray = deque.size() % 2 ? 1 : 0;
    int remain = stray ? deque.back() : -1;
    // 1. pair <a, b> 만들기 ! 이 때, a > b
    std::deque<std::pair<int, int> > pair;
    for (size_t i = 0; i < deque.size() - stray; i += 2) {
        std::pair<int, int> p;
        if (deque[i] > deque[i + 1]) pair.push_back(std::make_pair(deque[i], deque[i + 1]));
        else pair.push_back(std::make_pair(deque[i + 1], deque[i]));
    }
    std::cout << "=== pair <a, b> 만들기 ===" << std::endl;
    for (size_t i = 0; i < pair.size(); i++) {
        std::cout << pair[i].first << ", " << pair[i].second << std::endl;
    }
    // 2. a를 기준으로 정렬하기
    std::sort(pair.begin(), pair.end());
    std::cout << "=== a를 기준으로 정렬하기 ===" << std::endl;
    for (size_t i = 0; i < pair.size(); i++) {
        std::cout << pair[i].first << ", " << pair[i].second << std::endl;
    }
    // 3. main chain, pending elements 배열 만들기
    std::deque<int> main_chain, pending_elements;
    for (size_t i = 0; i < pair.size(); i++) {
        main_chain.push_back(pair[i].first);
        pending_elements.push_back(pair[i].second);
    }
    std::cout << "=== main chain ===" << std::endl;
    for (size_t i = 0; i < main_chain.size(); i++) {
        std::cout << main_chain[i] << " ";
    }
    std::cout << "\n=== pending elements ===" << std::endl;
    for (size_t i = 0; i < pending_elements.size(); i++) {
        std::cout << pending_elements[i] << " ";
    }
    if (stray) std::cout << "\n=== remain ===\n" << remain << std::endl;
}

void PmergeMe::sort(int size, char *input[]) {
    try {
        parseInput_D(size, input);
        checkValid_D();
        mergeInsertionSort_D();
        std::cout << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

const char* PmergeMe::AlreadySortedException::what() const throw() {
    return "already sorted";
}

const char* PmergeMe::BadInputException::what() const throw() {
    return "bad input";
}

const char* PmergeMe::DuplicateValueException::what() const throw() {
    return "duplicate value";
}