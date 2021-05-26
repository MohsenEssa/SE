#include <bits\stdc++.h>
using namespace std;

int calculatePower1(int base, int power); // O(power)
int calculatePower2(int base, int power); // O(log(power))

int main()
{
    int base, exponent;
    cout << "Enter number: ";
    cin >> base;
    cout << "\nEnter exponent: ";
    cin >> exponent;
    cout << "Result from first function = " << calculatePower1(base, exponent) << endl;
    cout << "Result from second function = " << calculatePower2(base, exponent) << endl;
    return 0;
}

int calculatePower1(int base, int power)
{
    return power ? base * calculatePower1(base, power - 1) : 1;
}

int calculatePower2(int base, int power)
{
    return power == 1 ? base : calculatePower2(base, power / 2) * calculatePower2(base, (power + 1) / 2);
}