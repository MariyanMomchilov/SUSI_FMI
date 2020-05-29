#ifndef _PCON
#define _PCON
#include <iostream>
#include "program.h"
#include <vector>

/// Класът представлява контейнер за Program
///
/// Член-данни: вектор(масив) от Program

class ProgramContainer
{
private:
    std::vector<Program> programs;
    friend std::ostream &operator<<(std::ostream &os, const ProgramContainer &pc);
    friend std::istream &operator>>(std::istream &is, ProgramContainer &pc);

public:
    /// Конструктор по подразбиране
    ProgramContainer() = default;

    /// @returns int размер на контейнера
    int size() const;

    /// Намира дадена програма по дадено име
    /// @param string име на програмата
    /// @returns Program
    Program getProgram(const std::string &) const;

    /// Проверява дали дадена програма се съдържа в контейнера
    /// @param Program програма
    /// @returns true ако е в контейнера. false иначе
    bool hasProgram(const Program &) const;

    /// Проверява дали дадена програма се съдържа в контейнера
    /// @param string име
    /// @returns true ако е в контейнера. false иначе
    bool hasProgram(const std::string &) const;

    /// Добавя нова програма в контейнера
    /// @param Program програма
    void addProgram(const Program &);

    /// Премахва дадена програма от контейнера
    /// @param Program програма
    void removeProgram(const Program &);

    /// Предефиниране на []
    Program operator[](int) const;

    /// Деструктор по подразбиране
    ~ProgramContainer() = default;
};

#endif