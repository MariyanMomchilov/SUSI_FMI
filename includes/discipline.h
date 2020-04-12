#ifndef _DIS
#define _DIS
#include <iostream>
#include <string>

class Discipline
{
private:
    std::string name;
    int type;
    int requiredCourse;
    int credits;

public:
    enum Type
    {
        Mandatory = 0,
        Selective
    };

    Discipline();
    Discipline(std::string, int, int, int);
    Discipline(const Discipline &);
    Discipline &operator=(const Discipline &);
    ~Discipline() = default;

    bool operator==(const Discipline &) const;
    std::string getName() const;
    int getType() const;
    int getRequiredCourse() const;
    int getCredits() const;
};

#endif