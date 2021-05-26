#ifndef PROBLEM_3_MATRIXCALCULATOR_H
#define PROBLEM_3_MATRIXCALCULATOR_H

#include "Matrix.h"
#include <bits\stdc++.h>
using namespace std;

class MatrixCalculator {
public:
    void calculator();
};

void MatrixCalculator::calculator()
{
    puts("Welcome to FCI Matrix Calculator\n"
         "----------------------------------------\n"
         "1- Perform Matrix Addition\n"
         "2- Perform Matrix Subtraction\n"
         "3- Perform Matrix Multiplication\n"
         "4- Matrix Transpose");
    int choice, n, m;
    cin >> choice;
    if (choice == 1)
    {
        puts("Enter first matrix");
        cin >> n >> m;
        Matrix<int> matrix1(n, m);
        cin >> matrix1;
        puts("Enter second matrix");
        cin >> n >> m;
        Matrix<int> matrix2(n, m);
        cin >> matrix2;
        puts("The addition of the two matrices is:");
        cout << matrix1 + matrix2 << '\n';
    }
    else if (choice == 2)
    {
        puts("Enter first matrix");
        cin >> n >> m;
        Matrix<int> matrix1(n, m);
        cin >> matrix1;
        puts("Enter second matrix");
        cin >> n >> m;
        Matrix<int> matrix2(n, m);
        cin >> matrix2;
        puts("The subtraction of the two matrices is:");
        cout << matrix1 - matrix2 << '\n';
    }
    else if (choice == 3)
    {
        puts("Enter first matrix");
        cin >> n >> m;
        Matrix<int> matrix1(n, m);
        cin >> matrix1;
        puts("Enter second matrix");
        cin >> n >> m;
        Matrix<int> matrix2(n, m);
        cin >> matrix2;
        puts("The multiplication of the two matrices is:");
        cout << matrix1 * matrix2 << '\n';
    }
    else if (choice == 4)
    {
        puts("Enter matrix");
        cin >> n >> m;
        Matrix<int> matrix(n, m);
        cin >> matrix;
        puts("The transpose of the matrix is:");
        cout << matrix.transpose() << '\n';
    }
}

#endif //PROBLEM_3_MATRIXCALCULATOR_H