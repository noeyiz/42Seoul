#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span& other) : n(other.n) {
    for (size_t i = 0; i < other.vector.size(); i++)
        vector.push_back(other.vector[i]);
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        n = other.n;
        vector.clear();
        for (size_t i = 0; i < other.vector.size(); i++)
            vector.push_back(other.vector[i]);
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (vector.size() == n) throw Span::OutOfRangeException();

    vector.push_back(num);
    std::sort(vector.begin(), vector.end());
}

unsigned int Span::shortestSpan() {
    if (vector.size() < 2) throw Span::NoSpanFoundException();

    unsigned int span = longestSpan();
    for (size_t i = 1; i < vector.size(); i++)
        span = std::min(span, static_cast<unsigned int>(vector[i]) - static_cast<unsigned int>(vector[i - 1]));

    return span;
}

unsigned int Span::longestSpan() {
    if (vector.size() < 2) throw Span::NoSpanFoundException();

    return static_cast<unsigned int>(vector[vector.size() - 1]) - static_cast<unsigned int>(vector[0]);
}

const char* Span::OutOfRangeException::what() const throw() {
    return "out of range";
}

const char* Span::NoSpanFoundException::what() const throw() {
    return "no span can be found";
}

const char* Span::BadRangeException::what() const throw() {
    return "bad range";
}
