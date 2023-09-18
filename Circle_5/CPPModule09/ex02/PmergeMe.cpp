#include "PmergeMe.hpp"

std::deque<int> PmergeMe::deque;
std::vector<int> PmergeMe::vector;

void PmergeMe::parseInput(int size, char **input) {
    // parse
    int num;
    for (int i = 0; i < size; i++) {
        std::istringstream ss(input[i]);
        ss >> num;
        if (!ss.eof() || num <= 0)
            throw BadInputException();
        deque.push_back(num);
        vector.push_back(num);
    }
    // check already sorted
    bool sorted = true;
    for (size_t i = 0; i < vector.size() - 1; i++) {
        if (vector[i] > vector[i + 1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) throw AlreadySortedException();
}

static void insertionSort_D(std::deque<std::pair<int, int> >& elements) {
    for (size_t i = 1; i < elements.size(); i++) {
        std::pair<int, int> value = elements[i];

        int j = i - 1;
        while (j >= 0 && elements[j].second > value.second) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = value;
    }
}

static void setJacobsthalNumber_D(std::deque<int>& jacobsthal_num, int size) {
    int prevprev = 1;  // J(n-2)
    int prev = 3;      // J(n-1)
    int curr = prev;   // J(n)

    jacobsthal_num.push_back(1);
    for (int i = 0; i < size - 1; i++) {
        if (curr == prevprev) {
            curr = prev + 2 * prevprev; // 점화식 : J(n) = J(n-1) + 2*J(n-2) (n >= 2)
            prevprev = prev;
            prev = curr;
        }
        if (curr > size) curr = size;
        jacobsthal_num.push_back(curr--);
    }
}

static void binarySearchSort_D(std::deque<int>& main_chain, int target, int start, int end) {
    if (start > end) {
        main_chain.insert(main_chain.begin() + start, target);
        return;
    }

    int mid = start + (end - start) / 2;

    if (main_chain[mid] < target) binarySearchSort_D(main_chain, target, mid + 1, end);
    else binarySearchSort_D(main_chain, target, start, mid - 1);
}

void PmergeMe::mergeInsertionSort_D() {
    // 1. 정렬할 원소의 개수가 홀수일 때 : 마지막 수 (remain) 저장
    int stray = vector.size() % 2 ? 1 : 0;
    int remain = deque.back();

    // 2. pair <b, a> 만들기 ! 이 때, b < a
    std::deque<std::pair<int, int> > elements;
    for (size_t i = 0; i < deque.size() - stray; i += 2) {
        if (deque[i] < deque[i + 1]) elements.push_back(std::make_pair(deque[i], deque[i + 1]));
        else elements.push_back(std::make_pair(deque[i + 1], deque[i]));
    }

    // 3. a를 기준으로 정렬하기
    insertionSort_D(elements);

    // 4. main chain 만들기
    std::deque<int> main_chain;
    for (size_t i = 0; i < elements.size(); i++)
        main_chain.push_back(elements[i].second);

    // 5. jacobsthal number에 따라 pending elements를 main chain 사이에.. 자리 찾아주기
    std::deque<int> jacobsthal_num;
    setJacobsthalNumber_D(jacobsthal_num, elements.size());
    for (size_t i = 0; i < elements.size(); i++) {
        std::pair<int, int> element = elements[jacobsthal_num[i] - 1];
        int end = std::find(main_chain.begin(), main_chain.end(), element.second) - main_chain.begin();
        binarySearchSort_D(main_chain, element.first, 0, end);
    }

    // 6. remain 있으면 자리 찾아주기
    if (stray) binarySearchSort_D(main_chain, remain, 0, main_chain.size() - 1);

    // 7. 정렬된 데이터 저장
    deque.clear();
    for (size_t i = 0; i < main_chain.size(); i++) deque.push_back(main_chain[i]);
}

static void insertionSort_V(std::vector<std::pair<int, int> >& elements) {
    for (size_t i = 1; i < elements.size(); i++) {
        std::pair<int, int> value = elements[i];

        int j = i - 1;
        while (j >= 0 && elements[j].second > value.second) {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = value;
    }
}

static void setJacobsthalNumber_V(std::vector<int>& jacobsthal_num, int size) {
    int prevprev = 1;  // J(n-2)
    int prev = 3;      // J(n-1)
    int curr = prev;   // J(n)

    jacobsthal_num.push_back(1);
    for (int i = 0; i < size - 1; i++) {
        if (curr == prevprev) {
            curr = prev + 2 * prevprev; // 점화식 : J(n) = J(n-1) + 2*J(n-2) (n >= 2)
            prevprev = prev;
            prev = curr;
        }
        if (curr > size) curr = size;
        jacobsthal_num.push_back(curr--);
    }
}

static void binarySearchSort_V(std::vector<int>& main_chain, int target, int start, int end) {
    if (start > end) {
        main_chain.insert(main_chain.begin() + start, target);
        return;
    }

    int mid = start + (end - start) / 2;

    if (main_chain[mid] < target) binarySearchSort_V(main_chain, target, mid + 1, end);
    else binarySearchSort_V(main_chain, target, start, mid - 1);
}

void PmergeMe::mergeInsertionSort_V() {
    // 1. 정렬할 원소의 개수가 홀수일 때 : 마지막 수 (remain) 저장
    int stray = vector.size() % 2 ? 1 : 0;
    int remain = vector.back();

    // 2. pair <b, a> 만들기 ! 이 때, b < a
    std::vector<std::pair<int, int> > elements;
    for (size_t i = 0; i < vector.size() - stray; i += 2) {
        if (vector[i] < vector[i + 1]) elements.push_back(std::make_pair(vector[i], vector[i + 1]));
        else elements.push_back(std::make_pair(vector[i + 1], vector[i]));
    }

    // 3. a를 기준으로 정렬하기
    insertionSort_V(elements);

    // 4. main chain 만들기
    std::vector<int> main_chain;
    for (size_t i = 0; i < elements.size(); i++)
        main_chain.push_back(elements[i].second);

    // 5. jacobsthal number에 따라 pending elements를 main chain 사이에.. 자리 찾아주기
    std::vector<int> jacobsthal_num;
    setJacobsthalNumber_V(jacobsthal_num, elements.size());
    for (size_t i = 0; i < elements.size(); i++) {
        std::pair<int, int> element = elements[jacobsthal_num[i] - 1];
        int end = std::find(main_chain.begin(), main_chain.end(), element.second) - main_chain.begin();
        binarySearchSort_V(main_chain, element.first, 0, end);
    }

    // 6. remain 있으면 자리 찾아주기
    if (stray) binarySearchSort_V(main_chain, remain, 0, main_chain.size() - 1);

    // 7. 정렬된 데이터 저장
    vector.clear();
    for (size_t i = 0; i < main_chain.size(); i++) vector.push_back(main_chain[i]);
}

void PmergeMe::sort(int size, char **input) {
    try {
        parseInput(size, input);
        
        std::cout << "Before: ";
        for (size_t i = 0; i < vector.size(); i++) std::cout << vector[i] << " ";
        std::cout << std::endl;

        clock_t start_time, end_time;
        double deque_time, vector_time;
        
        start_time = clock();
        mergeInsertionSort_D();
        end_time = clock();
        deque_time = static_cast<double>(end_time - start_time);
        
        start_time = clock();
        mergeInsertionSort_V();
        end_time = clock();
        vector_time = static_cast<double>(end_time - start_time);
        
        std::cout << "After: ";
        for (size_t i = 0; i < vector.size(); i++) std::cout << vector[i] << " ";
        std::cout << std::endl;

        std::cout << "Time to process a range of " << size << " elements with std::deque : " << deque_time << "ms" << std::endl;
        std::cout << "Time to process a range of " << size << " elements with std::vector : " << vector_time << "ms" << std::endl;
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
