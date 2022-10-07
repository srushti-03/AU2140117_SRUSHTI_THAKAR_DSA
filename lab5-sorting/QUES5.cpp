// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
// section-2

// Q5. Implement Mergesort Algorithm.


#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // first half of the array
    int n2 = right - mid;    // second half of the array
    int a[n1];               // declaring two temporary arrays for merging the individually sorted arrays
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = left; // beginning from the left side of the array
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // if the number of elements in both the arrays are unequal
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int left, int right)
{

    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid); // calling the mergeSort function recursively
                                 //  l: left end of the array ; r: right end of the array

        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "enter the number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "enter the value of elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);
    cout << "the array after sorting is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// output:

// Enter the number of elements: 5
// Enter elements:
// 123 23 45 67 98
// Array before Sorting: 123 23 45 67 98
// Array after Sorting: 23 45 67 98 123
