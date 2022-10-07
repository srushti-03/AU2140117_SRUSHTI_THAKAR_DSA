// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
//section-2

// Q2. Implement Selection Sort.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;       //considering the ith element to be the minElement

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])        
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];     //swapping the values of arr[i] and arr[minIndex]
        arr[minIndex] = temp;
    }
    cout << "the sorted array after selection sort is as follows: " << endl;
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
}

int main()
{

    int n;
    cout << "enter the size of the array: " << endl;
    cin >> n;
    int i;
    int arr[n];
    cout << "enter elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);
}


//output:

// enter the size of the array:
// 3
// enter elements of the array:
// 1 99 34
// the sorted array after selection sort is as follows:
// 1 34 99