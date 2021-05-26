#include "Fraction.h"
#include <bits\stdc++.h>
using namespace std;

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

Fraction Fraction::operator + (const Fraction& fraction) const
{
    return Fraction(this->numerator * fraction.denominator + this->denominator * fraction.numerator , this->denominator * fraction.denominator);
}

Fraction Fraction::operator - (const Fraction& fraction) const
{
    return *this + Fraction(-fraction.numerator, fraction.denominator);
}

Fraction Fraction::operator * (const Fraction& fraction) const
{
    return Fraction(this->numerator * fraction.numerator, this->denominator * fraction.denominator);
}

Fraction Fraction::operator / (const Fraction& fraction) const
{
    return *this * Fraction(fraction.denominator, fraction.numerator);
}

bool Fraction::operator < (const Fraction& fraction) const
{
    return (1.0 * numerator) / (1.0 * denominator) < (1.0 * fraction.numerator) / (1.0 * fraction.denominator);
}

bool Fraction::operator > (const Fraction& fraction) const
{
    return fraction < *this;
}

bool Fraction::operator == (const Fraction& fraction) const
{
    return !(*this < fraction) && !(*this > fraction);
}

bool Fraction::operator <= (const Fraction& fraction) const
{
    return !(*this > fraction);
}

bool Fraction::operator >= (const Fraction& fraction) const
{
    return !(*this < fraction);
}

void Fraction::simplify()
{
    int gcd = abs(__gcd(numerator, denominator));
    if (denominator < 0)
        gcd *= -1;
    numerator /= gcd;
    denominator /= gcd;
}

istream& operator >> (istream& in, Fraction& fraction)
{
    string str;
    in >> str;
    int index = str.find('/');
    if (index == string::npos)
    {
        fraction.numerator = stoi(str);
        fraction.denominator = 1;
        return in;
    }
    fraction.numerator = stoi(str.substr(0, index));
    fraction.denominator = stoi(str.substr(index + 1));
    return in;
}

ostream& operator << (ostream& out, Fraction& fraction)
{
    fraction.simplify();
    out << fraction.numerator;
    if (fraction.denominator != 1)
         out << '/' << fraction.denominator << '\n';
    return out;
}