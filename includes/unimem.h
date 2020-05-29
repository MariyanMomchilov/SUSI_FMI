#ifndef _UM
#define _UM
#include <iostream>
#include <string>

/// Клас, описващ човек, обвързан с Университета
///
/// Този клас е създаден с цел да е базов за всички типове хора в Университета (Студенти, Преподаватели и т.н)

class UniMember
{
private:
    std::string fName;
    std::string lName;
    int facN;

public:
    /// Kонструктор без параметри
    UniMember();

    /// Конструктор с параметри за име, фамилия, ФН
    UniMember(const std::string &, const std::string &, int);

    /// Копи-конструктор
    UniMember(const UniMember &);

    /// Предефиниране на =
    UniMember &operator=(const UniMember &);

    /// Предефиниране на =
    bool operator==(const UniMember &) const;

    /// Деструктор по подразбиране
    virtual ~UniMember() = default;

    /// @returns string име
    std::string getFname() const;

    /// @returns string фамилия
    std::string getLname() const;

    /// @returns int ФН
    int getFnumber() const;

    /// Присвоява стойност на име
    void setFname(const std::string &);

    /// Присвоява стойност на фамилия
    void setLname(const std::string &);

    /// Присвоява стойност на ФН
    void setFnumber(int);
};
#endif