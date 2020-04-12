#include "includes/student.h"

Student::Student() : UniMember(), status(0), year(0), group(0) {}
Student::Student(std::string _fn, std::string _ln, int FN, int stat, int y, int gr) : UniMember(_fn, _ln, FN), status(stat), year(y), group(gr) {}
Student::Student(std::string _fn, std::string _ln, int FN, int stat, int y, int gr, const Program &prog) : UniMember(_fn, _ln, FN), status(stat), year(y), group(gr), program(prog)
{
    for (int i = 0; i < program.getDiscSize(); i++)
    {
        addDisc(program.getDiscipline(i));
    }
}

Student::Student(const Student &obj) : UniMember(obj)
{
    status = obj.status;
    year = obj.year;
    group = obj.group;
    disciplines = obj.disciplines;
    grades = obj.grades;
    program = obj.program;
}

Student &Student::operator=(const Student &obj)
{
    if (this != &obj)
    {
        UniMember::operator=(obj);
        status = obj.status;
        year = obj.year;
        group = obj.group;
        disciplines = obj.disciplines;
        grades = obj.grades;
        program = obj.program;
    }
    return *this;
}

int Student::getStatus() const
{
    return status;
}

int Student::getYear() const
{
    return year;
}

int Student::getGroup() const
{
    return group;
}

Program Student::getProgram() const
{
    return program;
}

std::vector<int> Student::getGrades() const
{
    return grades;
}

std::vector<Discipline> Student::getDiscplines() const
{
    return disciplines;
}
double Student::getAvgGrade() const
{
    int size = grades.size();
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += grades[i];
    }
    return sum / size;
}
bool Student::operator==(const Student &obj) const
{
    return UniMember::operator==(obj) && status == obj.status && year == obj.year && group == obj.group && program == obj.program && disciplines == obj.disciplines && grades == obj.grades;
}
void Student::setStatus(int stat)
{
    assert(stat < 3 && stat > -1);
    status = stat;
}
void Student::setProgram(const Program &prog)
{
    program = prog;
}
void Student::setYear(int y)
{
    year = y;
}
void Student::setGroup(int g)
{
    group = g;
}

bool Student::isEnrolled(const Discipline &dis) const
{
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i] == dis)
            return true;
    }
    return false;
}
void Student::addDisc(const Discipline &dis)
{
    grades.push_back(2);
    disciplines.push_back(dis);
}
void Student::addGrade(const Discipline &dis, int mark)
{
    assert(mark > 1 && mark < 7);
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i] == dis)
        {
            grades[i] = mark;
        }
    }
}

int Student::getGrade(int i) const
{
    return grades[i];
}

bool Student::canPass() const
{
    int count_nevzeti = 0;
    for (int i = 0; i < disciplines.size(); i++)
    {
        if (disciplines[i].getRequiredCourse() <= year)
        {
            if (grades[i] == 2)
                count_nevzeti++;
        }
    }

    return count_nevzeti < 3;
}

bool Student::canGraduate() const
{
    int credits = 0;
    if (year == program.getYearsToGraduate())
    {
        for (int i = 0; i < disciplines.size(); i++)
        {
            if (grades[i] == 2)
                return false;
            else
                credits += disciplines[i].getCredits();
        }
        if (credits >= program.getCreditsToGraduate())
            return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Student &s)
{
    os << "Name: " << s.getFname() << " " << s.getLname() << '\n'
       << "FN: " << s.getFnumber() << '\n'
       << "Status: " << s.status << '\n'
       << "Year: " << s.year << '\n'
       << "Group: " << s.group << '\n'
       << "Program: " << s.program.getName() << '\n'
       << "Disciplines: " << '\n';

    for (int i = 0; i < s.disciplines.size(); i++)
    {
        os << s.disciplines[i].getName() << '\n';
    }
    os << std::endl;
    return os;
}