// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
// section-2

//Q4. Create best cases and worst cases for both sorts above and compare their timings.


//COMPARING THE BEST AND WORST CASES TIME COMPLEXITY OF SELECTION SEARCH AND INSERTION SEARCH (NORMAL)

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int minIndex = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
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
    auto start = chrono::steady_clock::now();
	int n;
	cout<<"enter the number of elements: "<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    
    selectionSort(arr, n);
    
   
    cout << "\n";
    auto stop = chrono::steady_clock::now();
    auto diff = stop - start;
    cout << "Time taken: ";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;

    
}

// output:

// 1. best case
// enter the number of elements:
// 4
// 4 3 2 1
// 1 2 3 4
// Time taken: 4341.6 ms


//2. worst case
// enter the number of elements: 
// 4
// 5 6 7 8
// the sorted array after selection sort is as follows: 
// 5 6 7 8
// Time taken: 5934.04 ms

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
} 

// Driver code
int main() {
   auto start = chrono::steady_clock::now();
	int n;
	cout<<"enter the number of elements: "<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    
    insertionSort(arr, n);
    
   
    cout << "\n";
    auto stop = chrono::steady_clock::now();
    auto diff = stop - start;
    cout << "Time taken: ";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
  
  
}

//output:


// 1. best case

// enter the number of elements: 
// 4
// 5 6 7 8
// 5 6 7 8 
// Time taken: 3521.55 ms


//2. worst case
// enter the number of elements: 
// 4
// 8 7 6 5
// 5 6 7 8 
// Time taken: 6056.12 ms














