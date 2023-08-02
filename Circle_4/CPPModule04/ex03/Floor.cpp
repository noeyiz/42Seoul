#include "Floor.hpp"

Floor::Floor(void) : materia_idx(0) {}

Floor::Floor(const Floor& other) : materia_idx(other.materia_idx) {
    for (int i = 0; i < FLOOR_SIZE; i++)
        arr[i] = other.arr[i]->clone();
}

Floor& Floor::operator=(const Floor& other) {
    if (this != &other) {
        for (int i = 0; i < FLOOR_SIZE; i++) {
            if (arr[i]) delete arr[i];
            arr[i] = other.arr[i]->clone();
        }
        materia_idx = other.materia_idx;
    }
    return *this;
}

Floor::~Floor(void) {
    for (int i = 0; i < FLOOR_SIZE; i++)
        if (arr[i]) delete arr[i];
}

void Floor::add_materia(AMateria *m) {
    if (arr[materia_idx]) delete arr[materia_idx];
    arr[materia_idx] = m;

    materia_idx = (materia_idx + 1) % FLOOR_SIZE;
}
