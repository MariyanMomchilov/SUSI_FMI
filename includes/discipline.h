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
    friend std::ostream &operator<<(std::ostream &os, const Discipline &obj);
    friend std::istream &operator>>(std::istream &is, Discipline &obj);

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