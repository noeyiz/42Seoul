#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : materia_idx(0) {}

MateriaSource::MateriaSource(const MateriaSource& other) : materia_idx(other.materia_idx) {
    for (int i = 0; i < SLOT_SIZE; i++)
        if (other.slot[i]) slot[i] = other.slot[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < SLOT_SIZE; i++) {
            if (slot[i]) delete slot[i];
            if (other.slot[i]) slot[i] = other.slot[i]->clone();
        }
        materia_idx = other.materia_idx;
    }
    return *this;
}

MateriaSource::~MateriaSource(void) {
    for (int i = 0; i < SLOT_SIZE; i++)
        if (slot[i]) delete slot[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (slot[materia_idx]) delete slot[materia_idx];
    slot[materia_idx] = m;

    materia_idx = (materia_idx + 1) % SLOT_SIZE;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < SLOT_SIZE; i++)
        if (type == slot[i]->getType()) return slot[i]->clone();
    return 0;
}
