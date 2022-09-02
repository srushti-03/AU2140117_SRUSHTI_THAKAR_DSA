
//AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS LAB-3



//ques-1: 2d array:

#include <bits/stdc++.h>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    int **a;

    // int a[row][col];
    Array2D(int r,int c){

        
        this->row=r;
        this->col=c;
        a = new int *[c];
        for (int i = 0; i < r; i++)
        {
            a[i] = new int[c];
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                a[i][j] = 0;
            }                                     //setting all values to 0 initially
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

    void clear(int value)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = value;
            }                                      // setting all indexes to a particular value
        }
    }

    int getItem(int i1,int i2)
    {
        return a[i1][i2];
    }

    void setItem(int i1,int i2, int val)
    {
        a[i1][i2]=val;
    }

    void display()
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
    int row, col;
    cin >> row >> col;
    Array2D a(row,col);   //creating an array object
    a.clear(7);
    a.setItem(2,1,10);
    cout<<a.getItem(2,3)<<endl;
    a.display();
}


// output:

// 4 4
// 7
// 7 7 7 7
// 7 7 7 7
// 7 10 7 7
// 7 7 7 7