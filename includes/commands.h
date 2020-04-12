#ifndef CMD_H
#define CMD_H

#include <iostream>
#include <fstream>
#include "susi.h"
class Commands
{
private:
    std::fstream file;
    void _open(std::string &, int &);
    std::string getNextCMD(std::string &, int &);
    Susi system; // TO DO

public:
    Commands() = default;
    Commands(const std::string &) = delete;
    void process(std::string &);

    ~Commands() = default;
};

#endif