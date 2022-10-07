// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
//section-2

// ques6: Implement Quicksort algorithm where the pivot is always the middle element.

#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right)
{

    int i = left, j = right;

    int temp;

    int pivot = arr[(left + right) / 2]; // taking the pivot as the middle most element

    while (i <= j)
    {

        while (arr[i] < pivot)

            i++;

        while (arr[j] > pivot)

            j--;

        if (i <= j)
        {

            temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;

            i++;

            j--;
        }
    };

    // calling the quicksort function recursively

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);
}

int main()
{
    int n;
    cout << "enter the number of elements: " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr, 0, n - 1);
    cout << "the array after quick sort is as follows: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

// output:

// enter the number of elements:
// 4
// 12 34 6 3
// the array after quick sort is as follows:
// 3 6 12 34