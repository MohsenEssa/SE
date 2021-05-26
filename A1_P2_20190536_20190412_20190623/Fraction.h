#ifndef PROBLEM_2_FRACTION_H
#define PROBLEM_2_FRACTION_H

#include <bits\stdc++.h>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1);
    Fraction operator + (const Fraction& fraction) const;
    Fraction operator - (const Fraction& fraction) const;
    Fraction operator * (const Fraction& fraction) const;
    Fraction operator / (const Fraction& fraction) const;
    bool operator < (const Fraction& fraction) const;
    bool operator > (const Fraction& fraction) const;
    bool operator == (const Fraction& fraction) const;
    bool operator <= (const Fraction& fraction) const;
    bool operator >= (const Fraction& fraction) const;
    void simplify();
    friend istream& operator >> (istream& in, Fraction& fraction);
    friend ostream& operator << (ostream& out, Fraction& fraction);
};


#endif //PROBLEM_2_FRACTION_H
