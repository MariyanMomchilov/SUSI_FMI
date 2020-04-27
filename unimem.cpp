#include "includes/unimem.h"

UniMember::UniMember() : fName(""), lName(""), facN(0) {}

UniMember::UniMember(const std::string &fN, const std::string &lN, int fNum) : fName(fN), lName(lN), facN(fNum) {}
UniMember::UniMember(const UniMember &mem)
{
    this->facN = mem.facN;
    this->fName = mem.fName;
    this->lName = mem.lName;
}
UniMember &UniMember::operator=(const UniMember &mem)
{
    this->facN = mem.facN;
    this->fName = mem.fName;
    this->lName = mem.lName;
    return *this;
}
bool UniMember::operator==(const UniMember &mem) const
{
    return fName == mem.fName && lName == mem.lName && facN == mem.facN;
}

std::string UniMember::getFname() const
{
    return this->fName;
}
std::string UniMember::getLname() const
{
    return this->lName;
}
int UniMember::getFnumber() const
{
    return this->facN;
}

void UniMember::setLname(const std::string &ln)
{
    lName = ln;
}

void UniMember::setFname(const std::string &fn)
{
    fName = fn;
}
void UniMember::setFnumber(int fn)
{
    facN = fn;
}