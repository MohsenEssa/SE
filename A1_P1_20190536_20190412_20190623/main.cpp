#include "BigDecimalInt.h"
#include <bits\stdc++.h>
using namespace std;

template <class T1, class T2>
void calculator(T1 num1, T2 num2, char operand);

int main()
{
    calculator("1230000000000000001", "30000000000000001", '-');
    cout << endl;
    calculator("-1230000000000000001", "30000000000000001", '+');
    cout << endl;
    calculator("-18", 772, '+');
    cout << endl;
    calculator("-18", 772, '-');
    cout << endl;
    calculator(170, "50000000000000", '-');
    return 0;
}

template <class T1, class T2>
void calculator(T1 num1, T2 num2, char operand)
{
    BigDecimalInt first(num1);
    BigDecimalInt second(num2);
    cout << "num1 = " << first << '\n';
    cout << "num2 = " << second << '\n';
    if (operand == '+')
        cout << "num1 + num2 = " << first + second << '\n';
    else if (operand == '-')
        cout << "num1 - num2 = " << first - second << '\n';
}

//puts("Welcome to FCAI Calculator");
//while (true)
//{
//puts("1- Perform Addition \n"
//"2- Perform Subtraction \n"
//"3- Exit ");
//int choice;
//cin >> choice;
//if (choice == 1)
//{
//puts("1- Big number"
//"2- number");
//cin >> choice;
//puts("Enter first number");
//BigDecimalInt first(0);
//if (choice == 1)
//{
//string num1;
//cin >> num1;
//cout << "num1 = " << num1 << '\n';
//}
//else
//{
//int num1;
//cin >> num1;
//cout << "num1 = " << num1 << '\n';
//}
//puts("1- Big number"
//"2- number");
//cin >> choice;
//puts("Enter first number");
//BigDecimalInt second(0);
//if (choice == 1)
//{
//string num1;
//cin >> num1;
//cout << "num1 = " << num1 << '\n';
//}
//else
//{
//int num1;
//cin >> num1;
//cout << "num1 = " << num1 << '\n';
//}
//cout << "num1 + num2 = " << first + second << '\n';
//}
//else if (choice == 2)
//{
//
//}
//else
//break;
//}