#ifndef _PRG
#define _PRG
#include "discipline.h"
#include <vector>
#include <string>
#include <cassert>

/// Класът описва дадена специалност
///
/// Класът съдържа данни за име, тип на специалността(Бакалавър, Магистър), период на обучение, капацитет, списък с задължителните дисциплини за специалността, необходим брой кредити за завършване

class Program
{
private:
    std::string name;
    int type;
    int yearsToGraduate;
    int capacity;
    std::vector<Discipline> disciplines;
    int creditsToGraduate; //само от избираеми, задължителните им се присвоява 0 кредити
    friend std::ostream &operator<<(std::ostream &os, const Program &prog);
    friend std::istream &operator>>(std::istream &is, Program &prog);

public:
    /*enum Type
    {
        Bachelor = 0,
        Master
    };*/

    /// Конструктор без параметри
    Program();

    /// Конструктор с параметри за име, тип, период на обучение, капацитет
    Program(const std::string &, int, int, int, int);

    /// Конструктор с параметри за име, тип, период на обучение, капацитет, списък със задължителни дисциплини, необходим брой кредити за завършване
    Program(const std::string &, int, int, int, const std::vector<Discipline> &, int);

    /// Копи-конструктор
    Program(const Program &);

    /// Предефиниране на =
    Program &operator=(const Program &);

    /// Деструктор по подразбиране
    ~Program() = default;

    /// Предефиниране на ==
    bool operator==(const Program &) const;

    /// @returns string име
    std::string getName() const;

    /// @returns int тип(Бакалавър - 0, Магистър - 1)
    int getType() const;

    /// @returns int капацитет
    int getCapacity() const;

    /// @returns int период на обучение
    int getYearsToGraduate() const;

    /// @returns int кредити
    int getCreditsToGraduate() const;

    /// Проверява дали в специалността се преподава дадена дисциплина
    /// @param Discipline дисциплина
    /// @returns true ако се преподава, false иначе
    bool hasDiscipline(const Discipline &) const;

    /// Добавя дисциплина в специалността, ако тази дисциплина я няма в списъка
    /// @param Discipline дисциплина
    void addDiscipline(Discipline);

    ///@returns size_t броя на задължителните дисциплини в специалността
    size_t getDiscSize() const;

    /// Връща дисциплина по даден пореден номер в списъка с дисциплини
    /// @param int пореден номер
    /// @returns Discipline
    Discipline getDiscipline(int) const;
};

#endif