#ifndef SUSI
#define SUSI
#include "student.h"

/// Класът описва системата СУСИ

class Susi
{
private:
    DisciplineContainer susi_disciplines;
    ProgramContainer susi_programs;
    std::vector<Student> susi_students;

    /// Намира индекс на Student във вектора от студенти по даден ФН
    /// @param int ФН
    /// @returns int >= 0 ако е намерен Student, -1 иначе
    int _studentIndex(int fn) const;

    friend std::ostream &operator<<(std::ostream &os, const Susi &susi);
    friend std::istream &operator>>(std::istream &is, Susi &susi);

public:
    /// Конструктор без параметри
    Susi();

    /// Намира Student във вектора от студенти по даден ФН, чрез _studentIndex()
    /// @param int ФН
    /// @returns Student
    Student getStudent(int fn) const;

    /// Намира Program по дадено име
    /// @param string име
    /// @returns Program
    Program getProgram(const std::string &name) const;

    /// Намира Discipline по дадено име
    /// @param string име
    /// @returns Disicpline
    Discipline getDiscipline(const std::string &name) const;

    /// Добавя дисциплина в DisciplineContainer
    /// @param Discipline
    void addToDisContainer(const Discipline &);

    /// Добавя специалност в ProgramContainer
    /// @param Program
    void addToProgContainer(const Program &);

    /// Записва студент в първи курс
    /// @param int ФН
    /// @param string име на специалност
    /// @param int група
    /// @param string име
    /// @param string фамилия
    void enroll(int fn, const std::string &program_name, int group, const std::string &fname, const std::string &lname);

    /// Записва студент в следващ курс
    /// @param int ФН
    void advance(int fn);

    /// Прехвърля студента с факултетен номер в нова специалност(program), група(group) или курс(year) зададени чрез<value>.Прехвърлянето в група е възможно винаги.Прехвърлянето в следващ курс е възможно само, ако студентът е положил успешно изпитите по всички задължителни предмети от минали курсове, с евентуално изключение на максимум два курса.Прехвърляне в курс, различен от следващия, не е възможно.Прехвърлянето в друга специалност е възможно само, ако студентът е положил успешно изпити по всички задължителни предмети от минали курсове на новата специалност.
    /// @param int ФН
    /// @param string опция
    /// @param string стойност
    void change(int fn, const std::string &option, const std::string &value);

    /// Прехвърля студента с факултетен номер в нова специалност(program), група(group) или курс(year) зададени чрез<value>.Прехвърлянето в група е възможно винаги.Прехвърлянето в следващ курс е възможно само, ако студентът е положил успешно изпитите по всички задължителни предмети от минали курсове, с евентуално изключение на максимум два курса.Прехвърляне в курс, различен от следващия, не е възможно.Прехвърлянето в друга специалност е възможно само, ако студентът е положил успешно изпити по всички задължителни предмети от минали курсове на новата специалност.
    /// @param int ФН
    /// @param string опция
    /// @param size_t стойност
    void change(int fn, const std::string &option, size_t value);

    /// Отбелязва студента като завършил, но само ако е положил успешно изпити по всички записани предмети
    /// @param int ФН
    void graduate(int fn);

    /// Маркира студента с факултетен номер като прекъснал. Прекъсналите студенти не могат да се явяват на изпити, да записват учебни дисциплини или да сменят специалност, група или курс
    /// @param int ФН
    void interrupt(int fn);

    /// Възстановява студентските права на студента с факултетен номер
    /// @param int ФН
    void resume(int fn);

    /// Извежда справка за студента с факултетен номер
    /// @param int ФН
    void print(int fn) const;

    ///Извежда справка за всички студенти в дадена специалност и курс
    /// @param string име на специалност
    /// @param int курс
    void printall(const std::string &program_name, int year) const;

    /// Записва студента с факултетен номер в дисциплината с име. Записването е позволено само на дисциплини от съответния курс и специалност
    /// @param int ФН
    /// @param string име на специалност
    void enrollin(int fn, const std::string &course_name);

    /// Добавя оценка по дисциплината на студента с факултетен номер. Явяването на изпит е позволено само за дисциплини, които са записани
    /// @param int ФН
    /// @param string име на специалност
    /// @param int оценка
    void addGrade(int fn, const std::string &course_name, int grade);

    /// Извежда протоколи за всички студенти, записани в дадена дисциплина. За всяка специалност и курс се извежда отделен протокол. Студентите в протокола са подредени по факултетен номер в нарастващ ред.
    /// @param string име на специалност
    void protocol(const std::string &course_name) const;

    /// Извежда академична справка за оценките на даден студент (списък с всички взети и невзети изпити, съответните оценки и успех на студента)    /// @param int ФН
    /// @param int ФН
    void report(int fn) const;

    /// Сортираща функция (selection sort) за вектора от Student
    void sort(std::vector<Student> &) const;

    /// Деструктор по подразбиране
    ~Susi() = default;
};

#endif
