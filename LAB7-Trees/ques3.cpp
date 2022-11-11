// AU2140117 
// SRUSHTI THAKAR
// DSA-DATA STRUCTURES AND ALGORITHMS
// section 2

// ques-3: implement heapsort algorithm using minheap

#include <bits/stdc++.h>
using namespace std;


// the function below creates a heap

void heap(int arr[], int n, int i)
{

    //let root be the smallest
	int mini = i;

	int left = 2 * i + 1;  // defining left 

	int right = 2 * i + 2; // defining right

	if (left < n && arr[left] < arr[mini])
		mini = left;

	if (right < n && arr[right] < arr[mini])
		mini = right;


	if (mini != i) {
		swap(arr[i], arr[mini]);

		// apply the heap function recursively to the subtrees
		heap(arr, n, mini);
	}
}

// heapsort function to sort the array
void heapSort(int arr[], int n)
{

	
	// we can heapify till the index n/2-1 as it is the last non leaf node
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, i);

	// extracting the elements one by one
	for (int i = n - 1; i > 0; i--) {

		
		swap(arr[0], arr[i]);

	
		heap(arr, i, 0);
	}
}


// dirver's code
int main()
{
	int arr[] = {10,20,50,30,15};
	int n = sizeof(arr) / sizeof(arr[0]);


	heapSort(arr, n);      //calling the heapsort function

	cout << "The array after heapsort using min heap is : ";
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}

//sample output:

// The array after heapsort using min heap is : 10 15 20 30 50 

