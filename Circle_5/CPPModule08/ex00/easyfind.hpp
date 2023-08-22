#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    return std::find(container.begin(), container.end(), value);
}

template <typename T>
typename T::iterator easyfind(const T& container, int value) {
    return std::find(container.begin(), container.end(), value);
}

#endif // EASYFIND_HPP