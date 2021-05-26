#ifndef PROBLEM_1_BIGDECIMALINT_H
#define PROBLEM_1_BIGDECIMALINT_H

#include <bits\stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    string num;
    string add(string a, string b, int i, int j) const;
    string subtract(string a, string b, int i, int j) const;
    bool isGreater(string a, string b) const;

public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator + (const BigDecimalInt& other) const;
    BigDecimalInt operator - (const BigDecimalInt& other) const;
    BigDecimalInt operator = (const BigDecimalInt& other);
    int size();
    friend ostream& operator << (ostream& out, const BigDecimalInt& bigInt);
};

string BigDecimalInt::add(string a, string b, int i, int j) const
{
    string res;
    bool carry = 0;
    while (i >= 0 || j >= 0)
    {
        short sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry)
        res += '1';
    return res;
}

string BigDecimalInt::subtract(string a, string b, int i, int j) const
{
    string res;
    bool borrow = 0;
    while (i >= 0)
    {
        short sub = -borrow;
        sub += a[i--] - '0';
        if (j >= 0)
            sub -= b[j--] - '0';
        res += sub < 0 ? (sub + 10) + '0' : sub + '0';
        borrow = sub < 0;
    }
    while (j >= 0)
        res.push_back(b[j--]);
    while (res.size() > 1 && res.back() == '0')
        res.pop_back();
    return res;
}

bool BigDecimalInt::isGreater(string a, string b) const
{
    if (a.length() > b.length())
        return true;
    if (a.length() < b.length())
        return false;
    for (int i = 0; i < a.length(); i++)
        if (b[i] > a[i])
            return false;
    return true;
}

BigDecimalInt::BigDecimalInt(string decStr)
{
    num = decStr;
}

BigDecimalInt::BigDecimalInt(int decInt)
{
    num = to_string(decInt);
}

BigDecimalInt BigDecimalInt::operator + (const BigDecimalInt& other) const
{
    int i = num.length() - 1, j = other.num.length() - 1;
    string res;
    if ((this->num)[0] != '-' && other.num[0] != '-')
        res = add(this->num, other.num, i, j);
    else if ((this->num)[0] == '-' && other.num[0] == '-')
    {
        i--, j--;
        res = add((this->num).substr(1), (other.num).substr(1), i, j);
        res += '-';
    }
    else
    {
        string num1, num2;
        if ((this->num)[0] == '-')
        {
            num1 = (this->num).substr(1);
            num2 = other.num;
            i--;
        }
        else
        {
            num1 = this->num;
            num2 = other.num.substr(1);
            j--;
        }
        bool greater = isGreater(num1, num2);
        bool negative = (greater && (this->num)[0] == '-') || (!greater && other.num[0] == '-');
        if (greater)
            res = subtract(num1, num2, i, j);
        else
            res = subtract(num2, num1, j, i);
        if (negative)
            res += '-';
    }
    reverse(res.begin(), res.end());
    return BigDecimalInt(res);
}

BigDecimalInt BigDecimalInt::operator - (const BigDecimalInt& other) const
{
    string str;
    if (other.num[0] == '-')
        str = other.num.substr(1);
    else
        str = '-' + other.num;
    BigDecimalInt subtraction = *this + BigDecimalInt(str);
    return subtraction;
}

BigDecimalInt BigDecimalInt::operator = (const BigDecimalInt& other)
{
    this->num = other.num;
    return *this;
}

int BigDecimalInt::size()
{
    return this->num.size();
}

ostream& operator << (ostream& out, const BigDecimalInt& bigInt)
{
    out << bigInt.num;
    return out;
}

#endif //PROBLEM_1_BIGDECIMALINT_H
