// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-4: insert element at the end of the array:


#include<iostream>
using namespace std;


int insertend(int arr[],int element,int n){
    n++;
    arr[n-1]=element;
    
    return n;
    
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
    
    int element;
    cin >> element;

    cout << "the array after inserting given element at the end is:" << endl;
    int m=insertend(arr,element,n);
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    return 0;


   
}

//sample output:

// 2
// 1 2
// 3
// the array after inserting given element at the end is:
// 1 2 3