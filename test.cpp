#define DOCTEST_CONFIG_IMPLEMENT
#include "includes/doctest.h"
#include "includes/unimem.h"
#include "includes/program.h"
#include "includes/progcontainer.h"
#include "includes/discontainer.h"
#include "includes/student.h"
#include "includes/susi.h"
/*#include "unimem.cpp"
#include "progcontainer.cpp"
#include "discontainer.cpp"
#include "discipline.cpp"
#include "program.cpp"
#include "student.cpp"
#include "susi.cpp"*/

using namespace std;
TEST_CASE(" UniMember obj ")
{
    UniMember mem("Daniel", "Angelov", 1234);
    CHECK(mem.getFname() == "Daniel");
    CHECK(mem.getFnumber() == 1234);

    UniMember mem2 = mem;
    CHECK(mem2.getFname() == "Daniel");
    CHECK(mem2.getFnumber() == 1234);
}

TEST_CASE(" Program obj ")
{
    Program KN("Komp nauki", 0, 4, 100, 30);
    KN.addDiscipline(Discipline("DIS", 0, 1, 0));
    KN.addDiscipline(Discipline("UP", 0, 1, 0));
    KN.addDiscipline(Discipline("OOP", 0, 2, 0));

    CHECK(KN.hasDiscipline(Discipline("UP", 0, 1, 0)));
    CHECK(KN.hasDiscipline(Discipline("UP", 0, 3, 0)) == false);
}

TEST_CASE("Program Container")
{
    ProgramContainer pc;

    Program KN("Komp nauki", 0, 4, 100, 30);
    Program I("Informatika", 0, 4, 70, 30);
    Program M("Matematika", 0, 4, 50, 30);
    KN.addDiscipline(Discipline("DIS", 0, 1, 0));
    KN.addDiscipline(Discipline("UP", 0, 3, 0));
    I.addDiscipline(Discipline("OOP", 0, 2, 0));
    M.addDiscipline(Discipline("DIS", 2, 1, 0));
    M.addDiscipline(Discipline("MAT", 1, 3, 0));
    M.addDiscipline(Discipline("DSTR", 3, 2, 0));

    pc.addProgram(KN);
    pc.addProgram(I);
    CHECK(pc.hasProgram(M) == false);
    pc.addProgram(M);

    CHECK(pc.hasProgram(M));
    CHECK(pc[0] == KN);
    CHECK(pc[2] == M);
    CHECK(pc.size() == 3);

    pc.removeProgram(I);
    CHECK(pc[1] == M);
    CHECK(pc.size() == 2);
}

TEST_CASE("Discipline Container")
{
    DisciplineContainer dc;
    dc.addDiscipline(Discipline("DIS", 0, 1, 0));
    dc.addDiscipline(Discipline("UP", 0, 3, 0));
    dc.addDiscipline(Discipline("OOP", 0, 2, 0));
    dc.addDiscipline(Discipline("DIS", 0, 1, 0));
    dc.addDiscipline(Discipline("MAT", 1, 3, 0));
    dc.addDiscipline(Discipline("DSTR", 3, 2, 0));
    CHECK(dc.size() == 5);
    CHECK(dc.hasDiscipline(Discipline("UP", 0, 3, 0)));
    dc.removeDiscipline(Discipline("UP", 0, 3, 0));
    CHECK(dc.hasDiscipline(Discipline("UP", 0, 3, 0)) == false);
    CHECK(dc.size() == 4);
}

TEST_CASE("Student")
{
    Student s1("Mariyan", "Momchilov", 8145, 0, 2, 2);

    Student s2 = s1;
    CHECK(s2 == s1);
    s2.addDisc(Discipline("OOP", 0, 1, 0));
    s2.addDisc(Discipline("UP", 0, 2, 0));
    s2.addGrade(Discipline("OOP", 0, 1, 0), 6);
    s2.addGrade(Discipline("UP", 0, 2, 0), 5);
    CHECK(s2.getAvgGrade() == 5.5);
    CHECK(s2.canPass());
    CHECK((s2 == s1) == false);
    Student s3 = Student("Mariyan", "Momchilov", 8145, 0, 1, 2);
    s3.addDisc(Discipline("OOP", 0, 1, 0));
    s3.addDisc(Discipline("UP", 0, 1, 0));
    s3.addDisc(Discipline("A1", 0, 1, 0));

    s3.addGrade(Discipline("OOP", 0, 1, 0), 2);
    s3.addGrade(Discipline("UP", 0, 1, 0), 2);
    s3.addGrade(Discipline("A1", 0, 1, 0), 5);
    CHECK(s3.canPass());

    CHECK(!(s2 == s3));
}

TEST_CASE(" SUSI commands ")
{

    Program KN("Komp nauki", 0, 4, 100, 30);
    Program I("Informatika", 0, 4, 70, 30);
    KN.addDiscipline(Discipline("DIS", 0, 1, 0));
    KN.addDiscipline(Discipline("UP", 0, 1, 0));
    KN.addDiscipline(Discipline("OS", 0, 1, 2));
    I.addDiscipline(Discipline("OOP", 0, 2, 0));

    Susi susi;
    susi.addToProgContainer(KN);
    susi.addToProgContainer(I);
    susi.enroll(81955, "Komp nauki", 2, "Mariyan", "Momchilov");
    susi.enroll(81955, "Informatika", 3, "Kiro", "Momchilov");
    susi.enroll(12345, "Informatika", 1, "Dragomir", "Binev");
    susi.report(81955);
    susi.report(12345);

    susi.advance(81955);
    CHECK(susi.getStudent(81955).getYear() == 1);

    Program Mat("Mat", 0, 2, 100, 5);
    Program IS("Inf sys", 0, 2, 70, 3);
    Mat.addDiscipline(Discipline("Funkcionalno", 0, 1, 3));
    Mat.addDiscipline(Discipline("UP", 0, 2, 2));
    IS.addDiscipline(Discipline("OOP", 0, 2, 1));
    IS.addDiscipline(Discipline("UP", 0, 1, 1));

    susi.addToDisContainer(Discipline("Funkcionalno", 0, 1, 3));
    susi.addToDisContainer(Discipline("UP", 0, 2, 2));
    susi.addToDisContainer(Discipline("OOP", 0, 2, 1));
    susi.addToDisContainer(Discipline("UP", 0, 1, 1));
    susi.addToProgContainer(Mat);
    susi.addToProgContainer(IS);
    susi.enroll(113, "Mat", 1, "Likiri", "Binev");
    susi.enroll(171, "Mat", 1, "Nikolai", "Kolev");
    susi.enroll(1111, "Mat", 1, "Kiril", "Binev");
    susi.addGrade(1111, "Funkcionalno", 4);
    susi.addGrade(1111, "UP", 3);
    susi.addGrade(113, "UP", 6);
    susi.advance(1111);
    CHECK(susi.getStudent(1111).getYear() == 2);
    susi.report(1111);

    susi.graduate(1111);
    CHECK(susi.getStudent(1111).getStatus() == Student::stat::Graduated);

    susi.enroll(1782, "Inf sys", 3, "Dimitar", "Dimov");
    susi.addGrade(1782, "UP", 3);

    susi.enroll(4112, "Inf sys", 3, "Angel", "Oreh");
    susi.addGrade(4112, "UP", 5);

    susi.enroll(1112, "Inf sys", 3, "Bobo", "Bobev");
    susi.report(1112);
}

/*TEST_CASE("Protocol")
{
    Susi susi;

    Program Mat("Mat", 0, 2, 100, 5);
    Program IS("Inf sys", 0, 2, 70, 3);
    Mat.addDiscipline(Discipline("Funkcionalno", 0, 1, 3));
    Mat.addDiscipline(Discipline("UP", 0, 1, 2));
    IS.addDiscipline(Discipline("OOP", 0, 2, 1));
    IS.addDiscipline(Discipline("UP", 0, 1, 2));

    susi.addToDisContainer(Discipline("Funkcionalno", 0, 1, 3));
    susi.addToDisContainer(Discipline("OOP", 0, 2, 1));
    susi.addToDisContainer(Discipline("UP", 0, 1, 2));
    susi.addToProgContainer(Mat);
    susi.addToProgContainer(IS);
    susi.enroll(113, "Mat", 1, "Likiri", "Binev");
    susi.enroll(171, "Mat", 1, "Nikolai", "Kolev");
    susi.enroll(1111, "Mat", 1, "Kiril", "Binev");
    susi.addGrade(1111, "Funkcionalno", 4);
    susi.addGrade(1111, "UP", 3);
    susi.addGrade(113, "UP", 6);
    susi.advance(1111);
    CHECK(susi.getStudent(1111).getYear() == 2);
    susi.report(1111);

    susi.graduate(1111);
    CHECK(susi.getStudent(1111).getStatus() == Student::stat::Graduated);

    susi.enroll(1782, "Inf sys", 3, "Dimitar", "Dimov");
    susi.addGrade(1782, "UP", 3);

    susi.enroll(4112, "Inf sys", 3, "Angel", "Oreh");
    susi.addGrade(4112, "UP", 5);

    susi.enroll(1112, "Inf sys", 3, "Bobo", "Bobev");
    susi.report(1112);

    std::cout << "PROTOKOL" << '\n';
    susi.protocol("UP");
}*/

TEST_CASE("Random test")
{
    Program KN("Komp nauki", 0, 4, 100, 30);
    KN.addDiscipline(Discipline("DIS", 0, 1, 0));
    KN.addDiscipline(Discipline("UP", 0, 1, 0));
    ProgramContainer pc;
    pc.addProgram(KN);
    Student s = Student("Mariyan", "Momchilov", 81955, 0, 1, 0, pc.getProgram(KN.getName()));
    CHECK(s.getProgram() == KN);
    CHECK(s.getProgram().getDiscipline(1) == Discipline("UP", 0, 1, 0));

    vector<Student> vs;
    vs.push_back(s);
    CHECK(vs[0] == s);
}

TEST_CASE("sort: program then name")
{

    Discipline d1("UP", 0, 1, 2);
    Discipline d2("A1", 0, 1, 2);
    Discipline d3("DIS", 0, 1, 2);
    DisciplineContainer dc;
    dc.addDiscipline(d1);
    dc.addDiscipline(d2);
    dc.addDiscipline(d3);

    Program KN("KN", 0, 1, 30, 4);
    KN.addDiscipline(dc[0]);
    KN.addDiscipline(dc[1]);

    Program I("I", 0, 1, 30, 2);
    I.addDiscipline(dc[2]);
    I.addDiscipline(dc[1]);

    Susi susi;
    susi.addToDisContainer(d1);
    susi.addToDisContainer(d2);
    susi.addToDisContainer(d3);

    susi.addToProgContainer(KN);
    susi.addToProgContainer(I);

    std::cout << "TEST !!" << endl;

    susi.enroll(123, "KN", 2, "Miro", "Kostov");
    susi.enroll(121, "KN", 1, "Angel", "Dimitrov");
    susi.enroll(111, "I", 1, "Boro", "Purvi");
    susi.enroll(112, "I", 3, "Dimo", "Kolev");
    std::vector<Student> vs;
    vs.push_back(susi.getStudent(123));
    vs.push_back(susi.getStudent(121));
    vs.push_back(susi.getStudent(111));
    vs.push_back(susi.getStudent(112));
    std::cout << vs[0] << '\n'
              << vs[1] << '\n'
              << vs[2] << '\n'
              << vs[3] << '\n';

    susi.protocol("A1");
}

int main()
{
    doctest::Context().run();
    return 0;
}