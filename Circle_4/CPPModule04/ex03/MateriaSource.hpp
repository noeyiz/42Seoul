#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define SLOT_SIZE 4

class MateriaSource : public IMateriaSource {
private:
    AMateria *slot[SLOT_SIZE];
    int materia_idx;

public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource(void);

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif // MATERIASOURCE_HPP