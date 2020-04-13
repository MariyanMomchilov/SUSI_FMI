#ifndef _PCON
#define _PCON
#include <iostream>
#include "program.h"
#include <vector>

class ProgramContainer
{
private:
    std::vector<Program> programs;
    friend std::ostream &operator<<(std::ostream &os, const ProgramContainer &pc);
    friend std::istream &operator>>(std::istream &is, ProgramContainer &pc);

public:
    ProgramContainer() = default;
    int size() const;
    Program getProgram(const std::string &) const;
    bool hasProgram(const Program &) const;
    bool hasProgram(const std::string &) const;
    void addProgram(const Program &);
    void removeProgram(const Program &);
    Program operator[](int) const;
    ~ProgramContainer() = default;
};

#endif