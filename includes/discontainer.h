#ifndef _DCON
#define _DCON
#include "discipline.h"
#include <vector>
#include <cassert>

class DisciplineContainer
{
private:
    std::vector<Discipline> disciplines;
    friend std::ostream &operator<<(std::ostream &os, const DisciplineContainer &obj);
    friend std::istream &operator>>(std::istream &is, DisciplineContainer &obj);

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