#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename T2>
void iter(T* arr, size_t size, T2 func) {
    for (size_t i = 0; i < size; i++)
        func(arr[i]);
}

#endif // ITER_HPP