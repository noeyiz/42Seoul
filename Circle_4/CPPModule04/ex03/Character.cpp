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
    for (int i = 0; i < SLOT_SIZE; i++)
        if (slot[i]) delete slot[i];
}

std::string const & Character::getName(void) const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < SLOT_SIZE; i++) {
        if (slot[i] == 0) {
            slot[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= SLOT_SIZE) return;
    if (slot[idx]) floor.add_materia(slot[idx]);
    slot[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= SLOT_SIZE) return;
    if (slot[idx]) slot[idx]->use(target);
}
