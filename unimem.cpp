#include "includes/unimem.h"
using namespace std;

UniMember::UniMember() : fName(""), lName(""), facN(0) {}

UniMember::UniMember(const string &fN, const string &lN, int fNum) : fName(fN), lName(lN), facN(fNum) {}
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

string UniMember::getFname() const
{
    return this->fName;
}
string UniMember::getLname() const
{
    return this->lName;
}
int UniMember::getFnumber() const
{
    return this->facN;
}