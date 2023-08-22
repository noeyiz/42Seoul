#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}
    MutantStack(const MutantStack& other) { this->c = other.c; }
    MutantStack& operator=(const MutantStack& other) { this->c = other.c; return *this; }
    ~MutantStack() {}

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const { return this->c.begin(); }
    const_iterator cbegin() const { return this->c.cbegin(); }
    const_iterator end() const { return this->c.end(); }
    const_iterator cend() const { return this->c.cend(); }

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator crbegin() const { return this->c.crbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
    const_reverse_iterator crend() const { return this->c.crend(); }
};

#endif // MUTANTSTACK_HPP