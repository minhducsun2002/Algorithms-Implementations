// Include Guard
#ifndef __MATRIX_HPP_INCLUDED__
#define __MATRIX_HPP_INCLUDED__

// forward declare
class Matrix;

// Include
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> __Edge;
// Vector of int
typedef vector<__Edge> __Matrix;
// Matrix of int

class Matrix
{
    int M = 1;
    // Side M
    int N = 1;
    // Side N

  public:
    __Matrix _Matrix;
    Matrix();
    Matrix(int, int, int);
    void Print();
    int at(int m, int n) { return _Matrix[m][n]; }
    void set(int m, int n, int val = 0) { if (m < M && n < N && m >= 0 && n >= 0) _Matrix[m][n] = val; }
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);

};
Matrix::Matrix()
{
    M = 1;
    N = 1;
    _Matrix.assign(M, __Edge(N, 0));
}
Matrix::Matrix(int m, int n, int val = 0)
{
    if (m < 1 || n < 1)
        return;
    M = m;
    N = n;
    _Matrix.assign(m, __Edge(n, val));
}
void Matrix::Print()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << _Matrix[i][j] << '\t';
        cout << endl;
    }
}

Matrix Matrix::operator+(const Matrix &param)
{
    Matrix temp(M, N);
    if (N == param.N && M == param.M)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                temp.set(i, j, this->_Matrix[i][j] + param._Matrix[i][j]);
    }
    return temp;
}
Matrix Matrix::operator-(const Matrix& param)
{
    Matrix temp(M, N);
    if (N == param.N && M == param.M)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                temp.set(i, j, this->_Matrix[i][j] - param._Matrix[i][j]);
    }
    return temp;
}
Matrix Matrix::operator*(const Matrix& param)
{
    Matrix temp(M, param.N);
    if (N == param.M)
    {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < param.N; j++)
            {
                int s = 0;
                for (int k = 0; k < N; k++)
                    s += this->_Matrix[i][k] * param._Matrix[k][j];
                temp.set(i, j, s);
            }
    }
    return temp;
}
#endif