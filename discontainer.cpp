#include "includes/discontainer.h"

int DisciplineContainer::size() const
{
    return disciplines.size();
}

bool DisciplineContainer::hasDiscipline(const Discipline &discipline) const
{
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i] == discipline)
            return true;
    }
    return false;
}

int DisciplineContainer::indexDiscipline(const std::string &name) const
{
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i].getName() == name)
            return i;
    }
    return -1;
}

void DisciplineContainer::addDiscipline(const Discipline &discipline)
{
    if (!hasDiscipline(discipline))
        disciplines.push_back(discipline);
}

void DisciplineContainer::removeDiscipline(const Discipline &discipline)
{
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i] == discipline)
            disciplines.erase(disciplines.begin() + i);
    }
}

Discipline DisciplineContainer::operator[](int i) const
{
    if (i < disciplines.size())
        return disciplines[i];
}

std::ostream &operator<<(std::ostream &os, const DisciplineContainer &obj)
{
    os << obj.size() << std::endl;
    for (int i = 0; i < obj.disciplines.size(); i++)
    {
        os << obj.disciplines[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, DisciplineContainer &obj)
{
    int size;
    is >> size;
    is.ignore();
    for (int i = 0; i < size; i++)
    {
        Discipline d;
        is >> d;
        obj.addDiscipline(d);
    }
    return is;
}