#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <fstream>
#include "susi.h"

/// Класът се използва за работа с командният ред

/// Член-данни: fstream file, име на файл, обект Susi

class Commands
{
private:
    std::fstream file;
    std::string filename;

    /// Отваря файл по дадена команда, като извлича параметрите дума по дума
    /// @param string команда
    /// @param int индекс, показващ до кой символ е стигнал обработването на командата
    void _open(std::string &, int &);

    /// Извлича параметър от дадена команда
    /// @param string команда
    /// @param int индекс, показващ до кой символ е стигнал обработването на командата
    /// @returns string текущият параметър от командата
    std::string getNextCMD(std::string &, int &);
    Susi system;

public:
    /// Конструктор по подразбиране
    Commands() = default;

    Commands(const std::string &) = delete;

    /// Изпълнява командата получена от командния ред ако е правилна
    /// @param string команда
    void process(std::string &);

    /// Зарежда информацията от файла в обекта Susi
    void write();

    /// Записва информацията от Susi във файла
    void read();

    /// Записва информацията от Susi във файла в произволен поток
    void write(std::ostream &os);

    /// Деструктор по подразбиране
    ~Commands() = default;
};

#endif