#ifndef _PRG
#define _PRG
#include "discipline.h"
#include <vector>
#include <string>
#include <cassert>

class Program
{
private:
    std::string name;
    int type;
    int yearsToGraduate;
    int capacity;
    std::vector<Discipline> disciplines;
    int creditsToGraduate; //само от избираеми

public:
    enum Type
    {
        Bachelor = 0,
        Master
    };

    Program();
    Program(const std::string &, int, int, int, int);
    Program(const std::string &, int, int, int, const std::vector<Discipline> &, int);
    Program(const Program &);
    Program &operator=(const Program &);
    ~Program() = default;

    bool operator==(const Program &) const;
    std::string getName() const;
    int getType() const;
    int getCapacity() const;
    int getYearsToGraduate() const;
    int getCreditsToGraduate() const;
    bool hasDiscipline(const Discipline &) const;
    void addDiscipline(Discipline);
    size_t getDiscSize() const;
    Discipline getDiscipline(int) const;
};

#endif