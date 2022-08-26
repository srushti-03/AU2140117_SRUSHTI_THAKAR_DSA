// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

// ques-3: delete element at a particular index in an array:


#include<iostream>
using namespace std;


int delatind(int arr[],int position,int n){
    
    int i;
    n--;
    for(i=position;i<n;i++){
        arr[i]=arr[i+1];


    }
    return n;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int position;
    cout<<"enter position to be deleted : ";
    cin>>position;
    int m=delatind(arr,position,n);
    cout<<"the array after deletion is :"<<" ";
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }

    
}

//sample output:

// 5
// 1 2 3 5 6
// enter position to be deleted : 2
// the array after deletion is : 1 2 5 6