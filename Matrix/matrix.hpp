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
    __Matrix _Matrix;

  public:
    Matrix();
    Matrix(int, int, int);
    void Print();
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

#endif