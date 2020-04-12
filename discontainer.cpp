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
    assert(i < disciplines.size());
    return disciplines[i];
}