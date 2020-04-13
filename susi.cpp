#include "includes/susi.h"
Susi::Susi() : susi_disciplines(), susi_programs() {}

void Susi::addToDisContainer(const Discipline &dis)
{
    susi_disciplines.addDiscipline(dis);
}
void Susi::addToProgContainer(const Program &prog)
{
    susi_programs.addProgram(prog);
}

Student Susi::getStudent(int fn) const
{
    int i = _studentIndex(fn);
    assert(i > -1);
    return susi_students[i];
}

Program Susi::getProgram(const std::string &name) const
{
    for (int i = 0; i < susi_programs.size(); i++)
    {
        if (name == susi_programs[i].getName())
            return susi_programs[i];
    }
    return Program();
}

Discipline Susi::getDiscipline(const std::string &name) const
{
    for (int i = 0; i < susi_disciplines.size(); i++)
    {
        if (name == susi_disciplines[i].getName())
            return susi_disciplines[i];
    }
    return Discipline();
}

int Susi::_studentIndex(int fn) const
{
    for (int i = 0; i < susi_students.size(); i++)
    {
        if (susi_students[i].getFnumber() == fn)
        {
            return i;
        }
    }
    return -1;
}

void Susi::enroll(int fn, const std::string &program_name, int group, const std::string &fname, const std::string &lname)
{
    assert(group > 0);

    if (_studentIndex(fn) != -1)
        std::cout << "Error, Student with this faculty number is already enrolled" << std::endl;

    else
    {
        if (susi_programs.hasProgram(program_name))
            susi_students.push_back(Student(fname, lname, fn, 0, 1, group, susi_programs.getProgram(program_name)));
        else
            std::cout << "There is no such Program" << std::endl;
    }
}

void Susi::advance(int fn)
{
    int i = _studentIndex(fn);
    if (i != -1)
    {
        if (susi_students[i].canPass())
        {
            susi_students[i].setYear(susi_students[i].getYear() + 1);
            std::cout << "Successful" << std::endl;
            return;
        }
        std::cout << "Unsuccessful" << std::endl;
    }
}

void Susi::graduate(int fn)
{
    int i = _studentIndex(fn);
    if (susi_students[i].canGraduate())
    {
        susi_students[i].setStatus(Student::stat::Graduated);
        std::cout << "Successful" << std::endl;
        return;
    }
    std::cout << "Unsuccessful" << std::endl;
}

void Susi::addGrade(int fn, const std::string &course_name, int grade)
{
    int i = _studentIndex(fn);
    assert(i > -1);
    if (susi_students[i].getStatus() == Student::stat::Dropout)
    {
        std::cout << "This student dropped out" << '\n';
        return;
    }
    for (int j = 0; j < susi_disciplines.size(); j++)
    {
        if (course_name == susi_disciplines[j].getName())
        {
            susi_students[i].addGrade(susi_disciplines[j], grade);
            std::cout << "Successful" << std::endl;
            return;
        }
    }
    std::cout << "Unsuccessful" << std::endl;
}

void Susi::interrupt(int fn)
{
    int i = _studentIndex(fn);
    assert(i > -1);
    susi_students[i].setStatus(Student::stat::Dropout);
    std::cout << "Successful" << std::endl;
}

void Susi::resume(int fn)
{
    int i = _studentIndex(fn);
    assert(i > -1);
    susi_students[i].setStatus(Student::stat::Active);
    std::cout << "Successful" << std::endl;
}

void Susi::print(int fn) const
{
    int i = _studentIndex(fn);
    assert(i > -1);
    susi_students[i].print();
}

void Susi::printall(const std::string &program_name, int year) const
{
    for (int i = 0; i < susi_students.size(); i++)
    {
        if (susi_students[i].getProgram().getName() == program_name && susi_students[i].getYear() == year)
        {
            susi_students[i].print();
            std::cout << '\n';
        }
    }
}

void Susi::enrollin(int fn, const std::string &course_name)
{
    int i = _studentIndex(fn);
    assert(i > -1);
    int di = susi_disciplines.indexDiscipline(course_name);
    assert(di > -1);
    susi_students[i].addDisc(susi_disciplines[di]);
}

void Susi::sort(std::vector<Student> &vs) const
{
    std::string currentProgramName = "";

    for (int i = 0; i < vs.size() - 1; i++)
    {
        for (int j = i + 1; j < vs.size(); j++)
        {
            if (vs[i].getProgram().getName() > vs[j].getProgram().getName())
            {
                Student tmp = vs[i];
                vs[i] = vs[j];
                vs[j] = tmp;
            }
            else if (vs[i].getProgram().getName() == vs[j].getProgram().getName())
            {
                if (vs[i].getFnumber() > vs[j].getFnumber())
                {
                    Student tmp = vs[i];
                    vs[i] = vs[j];
                    vs[j] = tmp;
                }
            }
        }
    }
}

void Susi::protocol(const std::string &course_name) const
{
    int di = susi_disciplines.indexDiscipline(course_name);
    assert(di > -1);
    std::vector<Student> studentProt;
    for (int i = 0; i < susi_students.size(); i++)
    {
        if (susi_students[i].isEnrolled(susi_disciplines[di]))
        {
            studentProt.push_back(susi_students[i]);
        }
    }

    Susi::sort(studentProt);
    std::string currentProgramName = "";
    for (int i = 0; i < studentProt.size(); i++)
    {
        if (currentProgramName != studentProt[i].getProgram().getName())
        {
            currentProgramName = studentProt[i].getProgram().getName();
            std::cout << "Protocol for program " << currentProgramName << std::endl;
        }
        std::cout << "Name: " << studentProt[i].getFname() << " " << studentProt[i].getLname() << '\n'
                  << "FN: " << studentProt[i].getFnumber() << '\n'
                  << "Status: " << studentProt[i].getStatus() << '\n'
                  << "Year: " << studentProt[i].getYear() << '\n'
                  << "Group: " << studentProt[i].getGroup() << '\n';
        //mqsto za ocenka po predmeta eventualno
    }
}

void Susi::report(int fn) const
{
    int i = _studentIndex(fn);
    assert(i > -1);
    std::vector<Discipline> izpiti = susi_students[i].getDiscplines();
    std::vector<int> nevzeti_index;
    std::cout << "Average grade:" << susi_students[i].getAvgGrade() << '\n';
    std::cout << "Passed:" << '\n';
    for (int j = 0; j < izpiti.size(); j++)
    {
        if (susi_students[i].getGrade(j) > 2)
        {
            std::cout << izpiti[j].getName() << " - " << susi_students[i].getGrade(j) << '\n';
        }
        else
        {
            nevzeti_index.push_back(j);
        }
    }
    std::cout << '\n'
              << "Failed:" << '\n';
    for (int j = 0; j < nevzeti_index.size(); j++)
    {
        std::cout << izpiti[nevzeti_index[j]].getName() << " - " << susi_students[i].getGrade(nevzeti_index[j]) << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Susi &susi)
{
    os << susi.susi_disciplines;
    os << susi.susi_programs;
    os << susi.susi_students.size() << std::endl;
    for (int i = 0; i < susi.susi_students.size(); i++)
    {
        os << susi.susi_students[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, Susi &susi)
{
    is >> susi.susi_disciplines;
    is >> susi.susi_programs;
    int stud_size;
    is >> stud_size;
    is.ignore();
    for (int i = 0; i < stud_size; i++)
    {
        Student stud;
        is >> stud;
        susi.susi_students.push_back(stud);
    }
    return is;
}

/*
void Susi::change(int fn, std::string option, std::string value);
*/