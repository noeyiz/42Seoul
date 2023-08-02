#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "AMateria.hpp"

# define FLOOR_SIZE 8

class Floor {
private:
    AMateria *arr[FLOOR_SIZE];
    int materia_idx;

public:
    Floor(void);
    Floor(const Floor& other);
    Floor& operator=(const Floor& other);
    ~Floor(void);

    void add_materia(AMateria *m);
};

#endif // FLOOR_HPP