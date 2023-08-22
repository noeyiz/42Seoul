#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
private:
    size_t _size;
    T *array;

public:
    Array() : _size(0), array(new T[0]) {}

    Array(unsigned int n) : _size(n), array(new T[n]) {}

    Array(const Array& other) : _size(other._size), array(new T[other._size]) {
        for (size_t i = 0; i < other._size; i++)
            array[i] = other.array[i];
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            _size = other._size;
            for (size_t i = 0; i < other._size; i++)
                array[i] = other.array[i];
        }
        return *this;
    }

    T& operator[](size_t idx) {
        if (idx < 0 || idx >= _size) throw std::exception();
        return array[idx];
    }

    ~Array() { delete[] array; }

    size_t size() { return _size; }
};

#endif // ARRAY_HPP