// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
// section-2

// Q8. Implement Radixsort Algorithm.

#include <iostream>
using namespace std;

// to find the maximum element in the array
int getMaximum(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the values based on their significant places
void countingSort(int array[], int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // to calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // to calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // for sorting the values
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// RadixSort main function
void radixSort(int array[], int size)
{
    // for getting maximum element
    int max = getMaximum(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

// for displaying the array
void display(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}


int main()
{
    int n;
    cout << " enter the number of elements: " << endl;
    cin >> n;
    int arr[n];
    cout << "enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr, n);
    cout << "the array after radix sort is as follows: " << endl;
    display(arr, n);
}

// output:

// enter the number of elements:
// 5
// enter the elements of the array:
// 123 4567 34 89 100
// the array after radix sort is as follows:
// 34 89 100 123 4567
