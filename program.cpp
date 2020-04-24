#include "includes/program.h"

Program::Program() : name(""), type(0), yearsToGraduate(4), capacity(0), creditsToGraduate() {}

Program::Program(const std::string &n, int t, int y, int c, int credits) : name(n), type(t), yearsToGraduate(y), capacity(c), creditsToGraduate(credits) {}
Program::Program(const std::string &n, int t, int y, int c, const std::vector<Discipline> &vec, int credits) : name(n), type(t), yearsToGraduate(y), capacity(c), disciplines(vec), creditsToGraduate(credits) {}
Program::Program(const Program &obj) : name(obj.name), type(obj.type), yearsToGraduate(obj.yearsToGraduate), capacity(obj.capacity), disciplines(obj.disciplines), creditsToGraduate(obj.creditsToGraduate) {}
Program &Program::operator=(const Program &obj)
{
    if (this != &obj)
    {
        name = obj.name;
        type = obj.type;
        yearsToGraduate = obj.yearsToGraduate;
        capacity = obj.capacity;
        disciplines = obj.disciplines;
        creditsToGraduate = obj.creditsToGraduate;
    }
    return *this;
}

bool Program::operator==(const Program &obj) const
{
    return name == obj.name && type == obj.type && yearsToGraduate == obj.yearsToGraduate && capacity == obj.capacity && disciplines == obj.disciplines;
}

std::string Program::getName() const
{
    return name;
}

int Program::getType() const
{
    return type;
}
int Program::getCapacity() const
{
    return capacity;
}

int Program::getCreditsToGraduate() const
{
    return creditsToGraduate;
}

int Program::getYearsToGraduate() const
{
    return yearsToGraduate;
}

bool Program::hasDiscipline(const Discipline &dis) const
{
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i] == dis)
            return true;
    }
    return false;
}
void Program::addDiscipline(Discipline dis)
{
    if (!hasDiscipline(dis))
        disciplines.push_back(dis);
}

Discipline Program::getDiscipline(int i) const
{
    if (i < disciplines.size())
        return disciplines[i];
}

size_t Program::getDiscSize() const
{
    return disciplines.size();
}

std::ostream &operator<<(std::ostream &os, const Program &prog)
{
    os << prog.name << std::endl;
    os << prog.type << ' ';
    os << prog.yearsToGraduate << ' ';
    os << prog.capacity << std::endl;
    os << prog.disciplines.size() << std::endl;
    for (int i = 0; i < prog.disciplines.size(); i++)
    {
        os << prog.disciplines[i];
    }
    os << prog.creditsToGraduate << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Program &prog)
{
    getline(is, prog.name);
    is >> prog.type;
    is >> prog.yearsToGraduate;
    is >> prog.capacity;
    int size;
    is >> size;
    is.ignore();
    for (int i = 0; i < size; i++)
    {
        Discipline d;
        is >> d;
        prog.disciplines.push_back(d);
    }
    is >> prog.creditsToGraduate;
    is.ignore();
    return is;
}