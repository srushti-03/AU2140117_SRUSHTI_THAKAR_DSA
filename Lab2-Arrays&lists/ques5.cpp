// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-5: insert element at the beginning of the array:


#include<iostream>
using namespace std;


int insertend(int arr[],int element,int n){
    n=n+1;
    for(int i=n;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=element;
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

    cout << "the array after inserting given element at the beginning is:" << endl;
    int m=insertend(arr,element,n);
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
    return 0;


   
}

//sample output:

// 3
// 1 2 3
// 8
// the array after inserting given element at the beginning is:
// 8 1 2 3