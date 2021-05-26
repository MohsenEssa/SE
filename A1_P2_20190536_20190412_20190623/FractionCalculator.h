#ifndef PROBLEM_2_FRACTIONCALCULATOR_H
#define PROBLEM_2_FRACTIONCALCULATOR_H

#include "Fraction.h"
#include <bits\stdc++.h>
using namespace std;

class FractionCalculator {
private:
    Fraction previous_result;

public:
    void calculator();
};

void FractionCalculator::calculator()
{
    puts("Welcome to FCI Fraction Calculator\n"
         "----------------------------------------\n"
         "1- Perform Fraction Addition\n"
         "2- Perform Fraction Subtraction\n"
         "3- Perform Fraction Multiplication\n"
         "4- Perform Fraction Division\n"
         "5- Exit");
    int choice;
    Fraction a, b, result;
    cin >> choice >> a >> b;
    switch (choice)
    {
        case 1:
            previous_result = a + b;
            break;
        case 2:
            previous_result = a - b;
            break;
        case 3:
            previous_result = a * b;
            break;
        case 4:
            previous_result = a / b;
        default:
            break;
    }
    cout << previous_result << '\n';
    while (true)
    {
        puts("Welcome to FCI Fraction Calculator\n"
             "----------------------------------------\n"
             "1- Perform Fraction Addition\n"
             "2- Perform Fraction Subtraction\n"
             "3- Perform Fraction Multiplication\n"
             "4- Perform Fraction Division\n"
             "5- Exit");
        cin >> choice;
        if (choice == 5)
            break;
        cin >> a;
        switch (choice)
        {
            case 1:
                result = previous_result + a;
                break;
            case 2:
                result = previous_result - a;
                break;
            case 3:
                result = previous_result * a;
                break;
            case 4:
                result = previous_result / a;
            default:
                break;
        }
        cout << result << '\n';
        previous_result = result;
    }
}

#endif //PROBLEM_2_FRACTIONCALCULATOR_H
