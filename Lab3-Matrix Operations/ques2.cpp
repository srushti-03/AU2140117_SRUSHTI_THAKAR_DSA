////AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS LAB 3

//ques-2 : Sparse matrix version :

#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Array2D
{
public:
    int row, col;
    int **a;
    vector<tuple<int, int, int>> t;
    Array2D(int r, int c)
    {
        this->row = r;
        this->col = c;
        a = new int *[c];
        for (int i = 0; i < r; i++)
        {
            a[i] = new int[c];
        }
    }

    int numRows()
    {
        return this->row;
    }

    int numCols()
    {
        return this->col;
    }

    // To clear matrix using given values
    void clear(int value)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = value;
            }
        }
    }
    // To clear Sparse matrix using given values
    void SparseClear(int value)
    {
        for (int i = 0; i < t.size(); i++)
        {
            get<0>(t[i]) = value;
            get<1>(t[i]) = value;
            get<2>(t[i]) = value;
        }
    }
    // TO get element at given index from a sparse matrix
    int getitem(int i1, int i2)
    {
        cout << "Element present at a particular index in a sparse matrix :";
        if (i2 == 0)
            return get<0>(t[i1]);
        else if (i2 == 1)
            return get<1>(t[i1]);
        else
            return get<2>(t[i1]);
    }

    void setitem(int i1, int i2, int value)
    {
        a[i1 - 1][i2 - 1] = value;
    }
    // makeMatrix will create sparse matrix based on the values given
    void makeMatrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (a[i][j] != 0)
                {
                    t.push_back(make_tuple(i, j,a[i][j]));
                }
            }
        }
    }
    // To print sparse matrix
    void PrintSparse()
    {
        for (int i = 0; i < t.size(); i++)
            cout << get<0>(t[i]) << " "
                 << get<1>(t[i]) << " "
                 << get<2>(t[i]) << "\n";
    }

    // To print normal matrix
    void print_it()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D Matrix1(5,5);
    Matrix1.clear(0);
   
    Matrix1.setitem(2, 2, 4);
    
    Matrix1.setitem(1, 4, 16);
    Matrix1.setitem(1, 3, 6);
    Matrix1.setitem(2, 4, 67);
    
    cout << "matrix1 : " << endl;
    Matrix1.print_it();
    cout << endl;
    cout << "Sparse matrix1: " << endl;
    Matrix1.makeMatrix();
    Matrix1.PrintSparse();
    cout << endl;
    cout << "Rows of sparse matrix: " << Matrix1.numRows() << endl;
    cout << "Column of sparse matrix: " << Matrix1.numCols() << endl;
    cout << Matrix1.getitem(1, 2);
    cout << endl;
    
    cout << endl;
    cout << "Cleared sparce matrix by givan value" << endl;
    Matrix1.SparseClear(7);
    Matrix1.PrintSparse();
    return 0;
}

// output:

// matrix1 : 
// 0 0 6 16 0
// 0 4 0 67 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0

// Sparse matrix1:
// 0 2 6
// 0 3 16
// 1 1 4
// 1 3 67

// Rows of sparse matrix: 5

// Column of sparse matrix: 5

// Element present at a particular index in a sparse matrix :16

// Cleared sparce matrix by givan value
// 7 7 7
// 7 7 7
// 7 7 7
// 7 7 7