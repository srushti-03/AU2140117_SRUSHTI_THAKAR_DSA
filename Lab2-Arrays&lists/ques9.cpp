// AU2140117 SRUSHTI THAKAR DATA STRUCTURES AND ALGORITHMS

// LAB 2

//ques-9: replacing element at a given index in an array:

#include<iostream>
using namespace std;

int *replace(int arr[],int position,int element,int n){
    arr[position-1]=element;
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

    cout << "the array after replacing given element at particular position is:" << endl;
    replace(arr, position, element,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
