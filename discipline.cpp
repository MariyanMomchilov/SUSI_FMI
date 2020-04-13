#include "includes/discipline.h"

Discipline::Discipline() : name(""), type(0), requiredCourse(1), credits(0) {}
Discipline::Discipline(std::string n, int t, int r, int cr) : name(n), type(t), requiredCourse(r), credits(cr) {}
Discipline::Discipline(const Discipline &obj) : name(obj.name), type(obj.type), requiredCourse(obj.requiredCourse), credits(obj.credits) {}
Discipline &Discipline::operator=(const Discipline &obj)
{
    if (this != &obj)
    {
        name = obj.name;
        type = obj.type;
        requiredCourse = obj.requiredCourse;
        credits = obj.credits;
    }
    return *this;
}

bool Discipline::operator==(const Discipline &obj) const
{
    return name == obj.name && type == obj.type && requiredCourse == obj.requiredCourse && credits == obj.credits;
}
std::string Discipline::getName() const
{
    return name;
}
int Discipline::getType() const
{
    return type;
}

int Discipline::getRequiredCourse() const
{
    return requiredCourse;
}

int Discipline::getCredits() const
{
    return credits;
}

std::ostream &operator<<(std::ostream &os, const Discipline &obj)
{
    os << obj.name << std::endl;
    os << obj.type << ' ';
    os << obj.requiredCourse << ' ';
    os << obj.credits << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Discipline &obj)
{
    getline(is, obj.name);
    is >> obj.type;
    is >> obj.requiredCourse;
    is >> obj.credits;
    is.ignore();
    return is;
}
