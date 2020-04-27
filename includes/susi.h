#ifndef SUSI
#define SUSI
#include "student.h"

class Susi
{
private:
    DisciplineContainer susi_disciplines;
    ProgramContainer susi_programs;
    std::vector<Student> susi_students;
    int _studentIndex(int fn) const;
    friend std::ostream &operator<<(std::ostream &os, const Susi &susi);
    friend std::istream &operator>>(std::istream &is, Susi &susi);

public:
    Susi();

    Student getStudent(int fn) const;
    Program getProgram(const std::string &name) const;
    Discipline getDiscipline(const std::string &name) const;

    void addToDisContainer(const Discipline &);
    void addToProgContainer(const Program &);
    void enroll(int fn, const std::string &program_name, int group, const std::string &fname, const std::string &lname);
    void advance(int fn);
    void change(int fn, const std::string &option, const std::string &value);
    void change(int fn, const std::string &option, size_t value);
    void graduate(int fn);
    void interrupt(int fn);
    void resume(int fn);
    void print(int fn) const;
    void printall(const std::string &program_name, int year) const;
    void enrollin(int fn, const std::string &course_name);
    void addGrade(int fn, const std::string &course_name, int grade);
    void protocol(const std::string &course_name) const;
    void report(int fn) const;
    void sort(std::vector<Student> &) const;

    ~Susi() = default;
};

#endif