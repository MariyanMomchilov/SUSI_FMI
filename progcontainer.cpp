#include "includes/progcontainer.h"

int ProgramContainer::size() const
{
    return programs.size();
}

bool ProgramContainer::hasProgram(const Program &program) const
{
    for (int i = 0; i < programs.size(); i++)
    {
        if (programs[i] == program)
            return true;
    }
    return false;
}

Program ProgramContainer::getProgram(const std::string &prog_name) const
{
    for (int i = 0; i < programs.size(); i++)
    {
        if (prog_name == programs[i].getName())
        {
            //std::cout << " Found " << prog_name << '\n'; дебъг само
            return programs[i];
        }
    }
    std::cout << "No program found" << '\n';
}

bool ProgramContainer::hasProgram(const std::string &program_name) const
{
    for (int i = 0; i < programs.size(); i++)
    {
        if (programs[i].getName() == program_name)
            return true;
    }
    return false;
}

void ProgramContainer::addProgram(const Program &program)
{
    if (!hasProgram(program))
        programs.push_back(program);
}

void ProgramContainer::removeProgram(const Program &program)
{
    for (int i = 0; i < programs.size(); i++)
    {
        if (programs[i] == program)
            programs.erase(programs.begin() + i);
    }
}

Program ProgramContainer::operator[](int i) const
{
    assert(i < programs.size());
    return programs[i];
}

std::ostream &operator<<(std::ostream &os, const ProgramContainer &pc)
{
    os << pc.programs.size() << std::endl;
    for (int i = 0; i < pc.programs.size(); i++)
    {
        os << pc.programs[i];
    }
    return os;
}
std::istream &operator>>(std::istream &is, ProgramContainer &pc)
{
    int size;
    is >> size;
    is.ignore();
    for (int i = 0; i < size; i++)
    {
        Program p;
        is >> p;
        pc.programs.push_back(p);
    }
    return is;
}
