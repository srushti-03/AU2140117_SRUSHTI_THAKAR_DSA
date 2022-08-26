// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

// ques-2. to insert an element at a given position in an array :


#include<iostream>
using namespace std;

int *insert(int arr[], int position, int element)
{
    int n = sizeof(arr);
    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    n++;
    return arr;
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
    int position;
    cin >> position;
    int element;
    cin >> element;

    cout << "the array after inserting given element at particular position is:" << endl;
    insert(arr, position, element);
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }
}

// output:

// 12 34 56 4 3
// 2
// 11
// the array after inserting given element at particular position is:
// 12
// 11
// 34
// 56
// 4
// 3
