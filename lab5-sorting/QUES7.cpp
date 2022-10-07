// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
// section-2

// Q7. Implement Quicksort algorithm where the pivot is chosen randomly.

#include <bits/stdc++.h>
using namespace std;
  
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) {
            i++; 
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return (i + 1);
}
  
int partition_r(int arr[], int low, int high)           //quicksort with random element chosen as pivot
{
    srand(time(NULL));
    int random = low + rand() % (high - low);
  
    swap(arr[random], arr[high]);
  
    return partition(arr, low, high);
}
  
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
  
        int pi = partition_r(arr, low, high);      //quicksort function
  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void display(int arr[], int size)
{                                            // display function for printing the elements
    int i;
    for (i = 0; i < size; i++)
        cout<<arr[i]<<" "; 
}
  
int main()
{
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before sorting is as follows : ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl; 
    quickSort(arr, 0, n - 1);
    cout << "Array after quicksort is as follows : ";
    display(arr, n);
      
    return 0;
}


//sample output:

// Enter number of elements : 4
// Enter elements of array: 12 3 45 10
// Array before sorting is as follows : 12 3 45 10 
// Array after quicksort is as follows : 3 10 12 45
