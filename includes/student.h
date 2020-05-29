#ifndef _ST
#define _ST
#include "unimem.h"
#include "progcontainer.h"
#include "discontainer.h"

/// Описва даден студент в СУСИ
///
/// Наследен от UniMember

class Student : public UniMember
{
private:
    int status;
    int year, group;
    Program program;
    std::vector<Discipline> disciplines;
    std::vector<int> grades;
    friend std::ostream &operator<<(std::ostream &os, const Student &s);
    friend std::istream &operator>>(std::istream &is, Student &s);

public:
    /*enum stat
    {
        Active = 0,
        Dropout,
        Graduated

    };*/

    /// Конструктор без параметри
    Student();

    /// Конструктор, приемащ като параметри име, фамилия, ФН, статус, курс, номер на група
    Student(const std::string &, const std::string &, int, int, int, int); //for test only

    /// Конструктор, приемащ като параметри име, фамилия, ФН, статус, курс, номер на група, обект от тип Program
    Student(const std::string &, const std::string &, int, int, int, int, const Program &);

    /// Копи-конструктор
    Student(const Student &);

    /// Предефиниране на =
    Student &operator=(const Student &);

    /// Деструктор по подразбиране
    ~Student() = default;

    /// @returns Статусът на студента
    int getStatus() const;

    /// @returns Текущият курс на студента
    int getYear() const;

    /// @returns Групата на студента
    int getGroup() const;

    /// @returns Обект от тип Program, съдържащ информация за специалността на студента
    Program getProgram() const;

    /// Проверява дали студентът може да премине в следващ курс
    ///
    /// @returns true ако студентът е има невзети по-малко от 3 изпита, false иначе
    bool canPass() const;

    /// Проверява дали студентът може да завърши специалността
    ///
    /// @returns true ако студентът е в най-горния за специалността, взел е всички изпити и е събрал нужните кредити. false иначе
    bool canGraduate() const;

    /// Проверява дали студентът си е взел всички изпити до момента
    ///
    /// @returns true ако студентът е взел всички изпити до момента. false иначе
    bool passedAll() const;

    /// Проверява дали студентът е записан в дадена дисциплина
    /// @param Discipline
    /// @returns true ако студентът е взел всички изпити до момента. false иначе
    bool isEnrolled(const Discipline &) const;

    /// Връща целочислен вектор(масив) от  оценките на студента
    std::vector<int> getGrades() const;

    /// Връща вектор(масив) от дисциплините, в които е записан студента
    ///
    /// @returns vector<Discipline>
    std::vector<Discipline> getDiscplines() const;

    /// Пресмята средно аритметично на оценките на студента
    double getAvgGrade() const;

    /// Дава оценката с пореден номер i във вектора от оценки
    ///
    /// @returns int
    int getGrade(int i) const;

    /// Предефиниране на ==
    bool operator==(const Student &) const;

    /// Присвоява статус в диапазона[0, 2]
    /// @param stat нов статус
    void setStatus(int stat);

    /// Присвоява нова специалност на студента
    /// @param Program Новата специалност
    void setProgram(const Program &);

    /// Присвоява курс
    void setYear(int y);

    /// Присвоява група
    void setGroup(int g);

    /// Добавя нова дисциплина в масива от дисциплини на студента
    ///
    /// При вмъкване на дисциплината се вмъква също и оценка(2) в масива от оценки
    void addDisc(const Discipline &);

    /// Нанасяне на оценка по дадена дисциплина
    /// @param Discipline дадената дисциплина
    /// @param int съответстващата оценка
    void addGrade(const Discipline &, int);

    void print() const;
};

#endif