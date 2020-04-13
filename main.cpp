#include "includes/commands.h"
#include "unimem.cpp"
#include "progcontainer.cpp"
#include "discontainer.cpp"
#include "discipline.cpp"
#include "program.cpp"
#include "student.cpp"
#include "commands.cpp"
#include "susi.cpp"

int main()
{
    Commands shell;

    std::string line;
    while (std::getline(std::cin, line))
    {
        shell.process(line);
    }

    return 0;
}