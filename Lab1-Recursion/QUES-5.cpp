// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS
#include <iostream>
using namespace std;

// ques-5. Write a function prodArray( ) that returns the product of the numbers in the array. It returns 1 if
//  the array is empty. For example, prodArray([2,5,10]) = 100.
int prodArray(int arr[], int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return arr[n - 1] * prodArray(arr, n - 1);
        ;
    }
}
int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int product = prodArray(arr, n);
    cout << product << endl;
}

// output:

// 4
// 1 2 3 1
// 6
