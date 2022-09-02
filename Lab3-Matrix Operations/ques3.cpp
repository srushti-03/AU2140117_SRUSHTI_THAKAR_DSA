//AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS LAB 3

//QUES-3: sparse matrix version:


#include <bits/stdc++.h>
using namespace std;




class array2D
{
public:
    int rows;
    int cols;
    int defaultValue;
    map<pair<int, int>, int> m1;

    array2D(int r, int c)
    {
        this->rows = r;
        this->cols = c;
        defaultValue = 0;
    }

    int numRows() { return this->rows; }  //returns number of rows

    int numCols() { return this->cols; }   //returns number of columns

    int getItem(int i1, int i2)
    {
        if (i1 >= 0 && i2 >= 0 && i1 < rows && i2 < cols)
        {
            int val = m1[{i1, i2}];
            if (val == 0 && defaultValue != val)
            {
                return defaultValue;
            }
            else
            {
                return val;
            }
        }
        else
        {
            throw invalid_argument("Index out of bound error");
        }
    }

    void setItem(int i1, int i2, int value)
    {
        if (i1 >= 0 && i2 >= 0 && i1 < rows && i2 < cols)
        {
            m1[{i1, i2}] = value;
        }
        else
        {
            throw invalid_argument("Index out of Bound error");
        }
    }

    void scaleBy(int s)
    {
        for (auto itr : m1)
        {
            m1[{itr.first.first,itr.first.second}] *= s;
        }
    }

    void transpose()
    {
        int transposeMatrix[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transposeMatrix[j][i] = m1[{i, j}];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols ; j++)
            {
                cout << transposeMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(int arr[3][3])
    {
        int addMatrix[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j <cols ; j++)
            {
                addMatrix[i][j] = m1[{i,j}] + arr[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout<<addMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
 }
    

    void subtract(int arr[3][3])
    {
        int subMatrix[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j <cols; j++)
            {
                subMatrix[i][j] = m1[{i,j}] - arr[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout<<subMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void multiply(int arr[3][3])
    {
        int newMatrix[rows][sizeof(arr[0])/sizeof(arr[0][0])] = {0};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    newMatrix[i][j]+=m1[{i,k}] * arr[k][j];
                    
                }
                cout<<newMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void printSparseMatrix()
    {
        cout << "Sparse Matrix:  "<<endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int val = m1[{i, j}];
                if (val == 0 && defaultValue != val)
                {
                    cout << defaultValue << " ";
                }
                else
                {
                    cout << val << " ";
                }
            }
            cout << "\n";
        }
        cout<<endl;
    }
    void printIndexes()
    {
        cout << "Index -> value\n"; 
        for (auto i : m1)
        {
            cout << (i.first.first) << ", " << (i.first.second) << " -> " << i.second << endl;
        }
    }
};

int main()
{
    array2D a(3,3);
    a.setItem(0, 1, 2);
    a.setItem(1, 1, 89);
    a.setItem(2, 2, 34);
    int b[3][3] = {{1,0,2},{1,3,5},{2,3,6}};
    
    a.printSparseMatrix();
    cout<<"The transpose of the matrix: "<<endl;
    a.transpose();
    cout<<endl;
    cout<<"The addition of 2 matrices: "<<endl;
    a.add(b);  
    cout<<endl;
    cout<<"The subtraction of 2 matrices: "<<endl;
    a.subtract(b);
    cout<<endl;
    cout<<"The Multiplication of 2 matrices: "<<endl;
    a.multiply(b);
    return 0;
}





// output:


// Sparse Matrix:  
// 0 2 0
// 0 89 0
// 0 0 34

// The transpose of the matrix:
// 0 0 0
// 2 89 0
// 0 0 34

// The addition of 2 matrices:
// 1 2 2
// 1 92 5
// 2 3 40

// The subtraction of 2 matrices:
// -1 2 -2
// -1 86 -5
// -2 -3 28

// The Multiplication of 2 matrices:
// 2 6 10
// 89 267 445
// 68 102 204