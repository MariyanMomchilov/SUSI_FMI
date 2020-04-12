#ifndef _DCON
#define _DCON
#include "discipline.h"
#include <vector>
#include <cassert>

class DisciplineContainer
{
private:
    std::vector<Discipline> disciplines;

public:
    DisciplineContainer() = default;
    int size() const;
    bool hasDiscipline(const Discipline &) const;
    int indexDiscipline(const std::string &) const;

    void addDiscipline(const Discipline &);
    void removeDiscipline(const Discipline &);
    Discipline operator[](int) const;
};

#endif