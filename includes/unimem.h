#ifndef _UM
#define _UM
#include <iostream>
#include <string>
class UniMember
{
private:
    std::string fName;
    std::string lName;
    int facN;

public:
    UniMember();
    UniMember(const std::string &, const std::string &, int);
    UniMember(const UniMember &);
    UniMember &operator=(const UniMember &);
    bool operator==(const UniMember &) const;
    ~UniMember() = default;
    std::string getFname() const;
    std::string getLname() const;
    int getFnumber() const;
};
#endif