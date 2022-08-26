// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

// QUES -1

// ques-1: to find the index of an element in the given array:

#include <iostream>
using namespace std;

int srch(int arr[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i + 1;
            break;
        }
    }

    return -1;
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
    int element;
    cin >> element;

    int index = srch(arr, element, n);
    cout << "the element is found at index: " << index << endl;
}

// output:

// 5
// 1 2 3 4 5
// 3
// the element is found at index: 3