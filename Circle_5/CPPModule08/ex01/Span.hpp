#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span {
private:
    unsigned int n;
    std::vector<int> vector;

    Span();

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int num);
    long long shortestSpan() const;
    long long longestSpan() const;

    template <typename T>
    void addNumbers(typename T::const_iterator begin, typename T::const_iterator end) {
        if (std::distance(begin, end) < 0) throw Span::BadRangeException();
        if (vector.size() + std::distance(begin, end) >= n) throw Span::OutOfRangeException();

        for (typename T::const_iterator it = begin; it != end; it++)
            vector.push_back(*it);
        std::sort(vector.begin(), vector.end());
    }

    template <typename T>
    void addNumbers(typename T::const_reverse_iterator begin, typename T::const_reverse_iterator end) {
        if (std::distance(begin, end) < 0) throw Span::BadRangeException();
        if (vector.size() + std::distance(begin, end) >= n) throw Span::OutOfRangeException();

        for (typename T::const_reverse_iterator it = begin; it != end; it++)
            vector.push_back(*it);
        std::sort(vector.begin(), vector.end());
    }

    class OutOfRangeException : public std::exception {
        virtual const char* what() const throw();
    };

    class NoSpanFoundException : public std::exception {
        virtual const char* what() const throw();
    };

    class BadRangeException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif // SPAN_HPP
