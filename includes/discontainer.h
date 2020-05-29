#ifndef _DCON
#define _DCON
#include "discipline.h"
#include <vector>
#include <cassert>

/// Класът представлява контейнер за Discipline
///
/// Член-данни: вектор(масив) от Discipline

class DisciplineContainer
{
private:
    std::vector<Discipline> disciplines;
    friend std::ostream &operator<<(std::ostream &os, const DisciplineContainer &obj);
    friend std::istream &operator>>(std::istream &is, DisciplineContainer &obj);

public:
    /// Конструктор по подразбиране
    DisciplineContainer() = default;

    /// @returns int размер на контейнера
    int size() const;

    /// Проверява дали дадена дисциплина се съдържа в контейнера
    /// @param Discipline дисциплина
    /// @returns true ако е в контейнера. false иначе
    bool hasDiscipline(const Discipline &) const;

    /// Намира индексът към дадена дисциплина по дадено име
    /// @param string име на дисциплина
    /// @returns int >= 0, ако е намерена, -1 иначе
    int indexDiscipline(const std::string &) const;

    /// Добавя нова дисциплина в контейнера
    /// @param Discipline дисциплина
    void addDiscipline(const Discipline &);

    /// Премахва дадена дисциплина от контейнера
    /// @param Discipline дисциплина
    void removeDiscipline(const Discipline &);

    /// Предефиниране на []
    Discipline operator[](int) const;
};

#endif