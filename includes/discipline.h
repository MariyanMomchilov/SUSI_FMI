#ifndef _DIS
#define _DIS
#include <iostream>
#include <string>

/// Описва диспиплина в СУСИ
///
/// Класът съдържа член-данни за име, тип(задължителна - 0/избираема - 1), необходим курс на студента за записване на тази дисциплина, брой кредити(задължителните носят 0)

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
    /*enum Type
    {
        Mandatory = 0,
        Selective
    };*/

    /// Конструктор без параметри
    Discipline();

    /// Конструктор приемащ за параметри име, тип, необходим курс за записване, кредити
    Discipline(std::string, int, int, int);

    /// Копи-конструктор
    Discipline(const Discipline &);

    /// Предефиниране на =
    Discipline &operator=(const Discipline &);

    /// Деструктор по подразбиране
    ~Discipline() = default;

    /// Предефиниране на ==
    bool operator==(const Discipline &) const;

    /// @returns string име
    std::string getName() const;
    /// @returns int тип
    int getType() const;

    /// @returns int необходим курс за да се запише дисциплината
    int getRequiredCourse() const;

    /// @returns int брой кредити
    int getCredits() const;
};

#endif