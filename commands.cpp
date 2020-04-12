#ifndef CMD_CPP
#define CMD_CPP
#include "includes/commands.h"

std::string Commands::getNextCMD(std::string &str, int &i)
{
    std::string command;
    int k = i + 1;
    if (str[k] == '\"' || str[k] == '\'')
    {
        if (str[k] == '\"')
        {
            str[k] = '|';
            i = str.find('\"');
        }

        else if (str[k] == '\'')
        {
            str[k] = '|';
            i = str.find('\'');
        }

        if (i == -1)
        {
            return command;
        }
        else
        {
            str[i] = '|';
            k++;
            while (k != i)
            {
                command += str[k];
                if (str[k] == ' ')
                    str[k] = '|';
                k++;
            }
        }
    }
    else
    {
        i = str.find(' ');
        if (i != -1)
        {
            if (i == k) // само когато предната параметър е завършил със "
            {
                str[i] = '|';
                k++;
                if (str[k] == '\"')
                {
                    str[k] = '|';
                    k++;
                    i = str.find('\"');
                }
                else
                    i = str.find(' ');
            }
            if (i == -1)
            {
                command = str.substr(k, str.length());
                i = str.length();
            }
            else
            {
                str[i] = '|';
                while (k != i)
                {
                    command += str[k];
                    k++;
                }
            }
        }
        else
        {
            command = str.substr(k, str.length());
            i = str.length();
        }
    }
    //std::cout << command << '\n';
    return command;
}

void Commands::_open(std::string &str, int &i)
{
    if (i == str.length())
    {
        std::cout << "Error: no parameter given" << '\n';
        return;
    }
    std::string parameter = getNextCMD(str, i);
    if (file.is_open())
    {
        std::cout << "A file is already open" << std::endl;
    }
    else if (parameter.length() != 0)
    {
        this->file.open(parameter, std::ios::out | std::ios::in | std::ios::app);
        if (this->file.good())
            std::cout << "Successfuly opened " << parameter << std::endl;
    }
    else
    {
        std::cout << "Error: undefined argument" << '\n';
    }
}

void Commands::process(std::string &command)
{
    int i = -1; // tracks the (start - 1) of the upcomming command
    std::string next_cmd = getNextCMD(command, i);
    if (next_cmd == "open")
    {
        _open(command, i); //_open parses the rest of the command
    }
    else if (next_cmd == "close")
    {
        if (this->file.is_open())
        {
            this->file.close();
            std::cout << "Successfully closed" << '\n';
        }
        else
        {
            std::cout << "There is no opened file!" << '\n';
        }
    }
    else if (next_cmd == "save")
    {
        std::cout << "TO DO save" << '\n';
    }
    else if (next_cmd == "saveas")
    {
        std::cout << "TO DO saveas" << '\n';
    }
    else if (next_cmd == "help")
    {
        std::cout << "The following commands are supported:'\n'"
                  << "open <file>         opens <file>'\n'"
                  << "close               closes currently opened file'\n'"
                  << "save                saves the currently opened file'\n'"
                  << "saveas <file>       saves the currently opened file in <file>'\n'"
                  << "help                prints this information'" << std::endl;
    }

    else
    {
        //std::cout << "Проект команда или грешна команда, ТО ДО" << '\n';
        if (next_cmd == "enroll")
        {
            unsigned int fn = std::stoi(getNextCMD(command, i));
            std::string program_name = getNextCMD(command, i);
            unsigned group = std::stoi(getNextCMD(command, i));
            std::string fname = getNextCMD(command, i);
            std::string lname = getNextCMD(command, i);
            if (program_name != "" && fname != "" && lname != "")
                system.enroll(fn, program_name, group, fname, lname);
            else
                std::cout << "Wrong parameters!" << std::endl;
        }
        else if (next_cmd == "add_discipline")
        {
            std::string disc_name = getNextCMD(command, i);
            std::string dtype = getNextCMD(command, i);
            if (dtype != "mandatory" && dtype != "selective" && disc_name != "")
            {
                std::cout << "Error: discipline types are only mandatory or selective / empty name" << '\n';
                return;
            }
            unsigned dtypen = (dtype == "mandatory") ? 0 : 1;
            unsigned requredCourse = std::stoi(getNextCMD(command, i));
            unsigned credits;
            if (dtype == "mandatory")
                credits = 0;
            else
                credits = std::stoi(getNextCMD(command, i));
            system.addToDisContainer(Discipline(disc_name, dtypen, requredCourse, credits));
        }
        else if (next_cmd == "add_program")
        {
            std::string program_name = getNextCMD(command, i);
            std::string ptype = getNextCMD(command, i);
            if (ptype != "bachelor" && ptype != "master" && program_name != "")
            {
                std::cout << "Error: program types are only bachelor or master / empty name" << '\n';
                return;
            }
            unsigned ptypen = (ptype == "bachelor") ? 0 : 1;
            unsigned yearToGraduate = std::stoi(getNextCMD(command, i));
            unsigned capacity = std::stoi(getNextCMD(command, i));
            unsigned numberOfMandatoryDisc = std::stoi(getNextCMD(command, i));
            std::string disc_name;
            std::vector<Discipline> disciplines;
            for (int k = 0; k < numberOfMandatoryDisc; k++)
            {
                disc_name = getNextCMD(command, i);
                disciplines.push_back(system.getDiscipline(disc_name));
                if (disciplines[k] == Discipline())
                {
                    std::cout << "Error: no such discipline with name " << disc_name << std::endl;
                    return;
                }
            }
            unsigned creditsToGraduate = std::stoi(getNextCMD(command, i));
            system.addToProgContainer(Program(program_name, ptypen, yearToGraduate, capacity, disciplines, creditsToGraduate));
            //std::cout << program_name << ", " << ptype << ", " << yearToGraduate << ", " << capacity << ", " << numberOfMandatoryDisc << ", " << creditsToGraduate << std::endl;
        }
        else if (next_cmd == "protocol")
        {
            std::string disc_name = getNextCMD(command, i);
            system.protocol(disc_name);
        }
        else if (next_cmd == "printall")
        {
            std::string prog_name = getNextCMD(command, i);
            unsigned year = std::stoi(getNextCMD(command, i));
            system.printall(prog_name, year);
        }
        else if (next_cmd == "print")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.print(fn);
        }
        else if (next_cmd == "advance")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.advance(fn);
        }
        else if (next_cmd == "graduate")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.graduate(fn);
        }
        else if (next_cmd == "resume")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.resume(fn);
        }
        else if (next_cmd == "interrupt")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.interrupt(fn);
        }
        else if (next_cmd == "addgrade")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            std::string disc_name = getNextCMD(command, i);
            unsigned grade = std::stoi(getNextCMD(command, i));
            system.addGrade(fn, disc_name, grade);
        }
        else if (next_cmd == "enrollin")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            std::string disc_name = getNextCMD(command, i);
            system.enrollin(fn, disc_name);
        }
        else if (next_cmd == "report")
        {
            unsigned fn = std::stoi(getNextCMD(command, i));
            system.report(fn);
        }
    }
}
#endif
