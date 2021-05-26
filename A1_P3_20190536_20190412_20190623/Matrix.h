#ifndef PROBLEM_3_MATRIX_H
#define PROBLEM_3_MATRIX_H

#include <bits\stdc++.h>
using namespace std;

template<class T>
class Matrix
{
private:
    int n, m;
    int** values;

public:
    Matrix(int rows, int columns);
    Matrix<T> operator + (Matrix<T>& matrix);
    Matrix<T> operator - (Matrix<T>& matrix);
    Matrix<T> operator * (Matrix<T>& matrix);
    Matrix<T> transpose();
    template<class U>
    friend istream& operator >> (istream& in, Matrix<U>& matrix);
    template<class U>
    friend ostream& operator << (ostream& out, const Matrix<U>& matrix);
    ~Matrix();
};

template<class T>
Matrix<T>::Matrix(int rows, int columns) : n(rows), m(columns)
{
    values = new int*[n];
    for (int i = 0; i < n; i++)
        values[i] = new int[m];
}

template<class T>
Matrix<T> Matrix<T>::operator + (Matrix<T>& matrix)
{
    assert((this->n == matrix.n) && (this->m == matrix.m));
    Matrix<T> res(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res.values[i][j] = values[i][j] + matrix.values[i][j];
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator - (Matrix<T>& matrix)
{
    assert((this->n == matrix.n) && (this->m == matrix.m));
    Matrix<T> res(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res.values[i][j] = values[i][j] - matrix.values[i][j];
    return res;
}

template<class T>
Matrix<T> Matrix<T>::operator * (Matrix<T>& matrix)
{
    assert(this->m == matrix.n);
    Matrix<T> res(this->n, matrix.m);

    for (int i = 0; i < res.n; i++)
        for (int j = 0; j < res.m; j++)
            res.values[i][j] = 0;

    for (int i = 0; i < res.n; i++)
        for (int j = 0; j < res.m; j++)
            for (int k = 0; k < this->m; k++)
                res.values[i][j] += values[i][k] * matrix.values[k][j];
    return res;
}

template<class T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> transposed(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            transposed.values[i][j] = values[j][i];
    return transposed;
}

template<class T>
istream& operator >> (istream& in, Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.n; i++)
        for (int j = 0; j < matrix.m; j++)
            in >> matrix.values[i][j];
    return in;
}

template<class T>
ostream& operator << (ostream& out, const Matrix<T>& matrix)
{
    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
            out << matrix.values[i][j] << ' ';
        out << endl;
    }
    return out;
}

template<class T>
Matrix<T>::~Matrix()
{
    for ( int i = 0; i < n; i++)
        delete[] values[i];
    delete[] values;
}

#endif //PROBLEM_3_MATRIX_H
