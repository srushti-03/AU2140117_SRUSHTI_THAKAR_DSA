// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
// section-2

//QUES 3:Implement Insertion Sort with the idea that the location of the next element in the sorted portion is found using binary search.

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int item, int low, int high)
{
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (item == a[mid])
			return mid + 1;
		else if (item > a[mid])
			low = mid + 1;           // searches for the position of the element by dividing the constantly dividing the array into halves
		else
			high = mid - 1;
	}

	return low;
}

// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; i++) {
        selected = a[i];
		j = i - 1;
		

		// find location where selected should be inseretd
		loc = binarySearch(a, selected, 0, j);

		while (j>=0 && j >= loc) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}




    int main()
{

    auto start = chrono::steady_clock::now();       //chrono function used to find the time of execution
	int n;
	cout<<"enter the number of elements: "<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    auto stop = chrono::steady_clock::now();
    auto diff = stop - start;
    cout << "Time taken: ";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}


//output:

// 1. Best case : elements are already sorted

// enter the number of elements: 
// 4
// 1 2 3 4
// 1 2 3 4 
// Time taken: 4752.74 ms


// 2. Worst case: elements are in the decreasing order

// enter the number of elements: 
// 4
// 4 3 2 1
// 1 2 3 4 
// Time taken: 5235.7 ms





//without using binary search approach 


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
// 1 2 3 4
// 1 2 3 4 
// Time taken: 3338.63 ms


// 2. worst case

// enter the number of elements: 
// 4
// 4 3 2 1
// 1 2 3 4 
// Time taken: 4341.6 ms

