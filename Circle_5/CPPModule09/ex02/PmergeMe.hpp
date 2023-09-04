#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <deque>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>

class PmergeMe {
private:
    static std::deque<int> deque;
    // static std::vector<int> vector;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static void parseInput_D(int size, char *input[]);
    static void checkValid_D();
    static void mergeInsertionSort_D();

public:
    static void sort(int size, char *input[]);

    class AlreadySortedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class BadInputException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class DuplicateValueException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif // PMERGEMEE_HPP