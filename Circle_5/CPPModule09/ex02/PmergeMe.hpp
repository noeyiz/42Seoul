#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <ctime>
# include <deque>
# include <iostream>
# include <sstream>
# include <string>
# include <utility>
# include <vector>

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"

class PmergeMe {
private:
    static std::deque<int> deque;
    static std::vector<int> vector;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void parseInput(int size, char **input);
    static void mergeInsertionSort_D();
    static void parseInput_V(int size, char **input);
    static void mergeInsertionSort_V();

public:
    static void sort(int size, char **input);

    class AlreadySortedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class BadInputException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // PMERGEMEE_HPP