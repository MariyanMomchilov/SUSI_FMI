#ifndef _ST
#define _ST
#include "unimem.h"
#include "progcontainer.h"
#include "discontainer.h"

class Student : public UniMember
{
private:
    int status;
    int year, group;
    Program program;
    std::vector<Discipline> disciplines;
    std::vector<int> grades;

public:
    enum stat
    {
        Active = 0,
        Dropout,
        Graduated

    };
    Student();
    Student(std::string, std::string, int, int, int, int); //for test only
    Student(std::string, std::string, int, int, int, int, const Program &);
    Student(const Student &);
    Student &operator=(const Student &);
    ~Student() = default;

    int getStatus() const;
    int getYear() const;
    int getGroup() const;
    Program getProgram() const;
    bool canPass() const;
    bool canGraduate() const;
    bool isEnrolled(const Discipline &) const;
    std::vector<int> getGrades() const;
    std::vector<Discipline> getDiscplines() const;
    double getAvgGrade() const;
    int getGrade(int i) const;
    bool operator==(const Student &) const;
    void setStatus(int stat);
    void setProgram(const Program &);
    void setYear(int y);
    void setGroup(int g);
    void addDisc(const Discipline &);
    void addGrade(const Discipline &, int);

    friend std::ostream &operator<<(std::ostream &, const Student &);
};

#endif