#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(void) : name("(null)") {}

Character::Character(std::string name) : name(name) {}

Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < SLOT_SIZE; i++)
        if (other.slot[i]) slot[i] = other.slot[i]->clone();
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < SLOT_SIZE; i++) {
            if (slot[i]) delete slot[i];
            if (other.slot[i]) slot[i] = other.slot[i]->clone();
        }
    }
    return *this;
}

Character::~Character(void) {
    for (int i = 0; i < materia_idx; i++) delete slot[i];
}

std::string const & Character::getName(void) const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < SLOT_SIZE; i++)
        if (slot[i] == 0) slot[i] = m->clone();
}

void Character::unequip(int idx) { // 버린 재료 leak
    if (idx < 0 || idx >= SLOT_SIZE) return;
    slot[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= materia_idx) return;
    slot[idx]->use(target);
}
