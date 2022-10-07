// AU2140117
// SRUSHTI THAKAR
// DSA: LAB5-SORTING
//section-2


//Q1. Implement Bubble Sort with the idea that if there are no exchanges in a particular pass (round), then the sort terminates.


//the bubble sort swaps the adjacent elements if the order is incorrect , thus the heaviest elements get settled at the end of the array after every pass
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j+1];
                arr[j+1]=arr[j];                 // swapping the values of arr[j] and arr[j+1] ,if the order is not proper
                arr[j]=t;
            }
        }
    }
     cout<<"the sorted array after bubble sort is as follows: "<<endl;
    for(int i=0;i<n;i++){
       
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"enter the size of the array: "<<endl;
    cin>>n;
    int i;
    int arr[n];
    cout<<"enter elements of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    bubbleSort(arr,n);

}



//output:

// enter the size of the array: 
// 4
// enter elements of the array: 
// 12 56 3 89
// the sorted array after bubble sort is as follows: 
// 3 12 56 89

