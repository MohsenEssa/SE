#include "StudentName.h"
#include <bits\stdc++.h>
using namespace std;

int main()
{
    puts("1st example");
    auto* studentName = new StudentName("Khaled");
    puts("Before replacing");
    studentName->print();
    cout << "Valid replace = " << (studentName->replace(2, 3) ? "True" : "False") << endl;
    puts("After replacing");
    studentName->print();
    cout << endl;
    //---------------------------------------------------------------

    puts("2nd example");
    auto* studentName2 = new StudentName("sara ahmed");
    puts("Before replacing");
    studentName2->print();
    cout << "Valid replace = " << (studentName2->replace(3, 0) ? "True" : "False") << endl;
    puts("After replacing");
    studentName2->print();
    cout << endl;
    //---------------------------------------------------------------

    puts("3rd example");
    auto* studentName3 = new StudentName("Osama Ahmed");
    puts("Before replacing");
    studentName3->print();
    cout << "Valid replace = " << (studentName3->replace(3, 1) ? "True" : "False") << endl;
    puts("After replacing");
    studentName3->print();
    cout << endl;
    //---------------------------------------------------------------

    puts("4th example");
    auto* studentName4 = new StudentName("ahmed Mohamed sayed");
    puts("Before replacing");
    studentName4->print();
    cout << "Valid replace = " << (studentName4->replace(2, 1) ? "True" : "False") << endl;
    puts("After replacing");
    studentName4->print();
    cout << endl;
    //---------------------------------------------------------------

    puts("5th example");
    auto* studentName5 = new StudentName("aya ali ahmed sayed");
    puts("Before replacing");
    studentName5->print();
    cout << "Valid replace = " << (studentName5->replace(5, 3) ? "True" : "False") << endl;
    puts("After replacing");
    studentName5->print();
    cout << endl;
    return 0;
}
