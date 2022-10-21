// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// ques-2 (part-B): secondary clustering

#include <bits/stdc++.h>
#define SIZE 7 // defining SIZE as 7

using namespace std;

int Hash(int key)
{
    return key % SIZE; // defining the hash function
}

int QuadraticProbe(int H[], int key)
{
    int index = Hash(key); // the quadratic probing function, used when there are collisions at a given position
    int i = 0;
    while (H[(index + i * i) % SIZE] != 0)
    {
        i++;
    }
    return (index + i) % SIZE;
}

void Insert(int H[], int key)
{
    int index = Hash(key); // inserting into the hash table

    if (H[index] != 0)
    {
        index = QuadraticProbe(H, key);
    }
    H[index] = key;
}

int Search(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != key)
    {
        i++; // searching the key in the hash table
        if (H[(index + i) % SIZE] == 0)
        {
            return -1;
        }
    }
    cout << key;
    return (index + i) % SIZE;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } // displaying the hash table
    cout << endl;
}

int main()
{

    int arr[] = {7,14,21,35,31,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array: " << endl;
    display(arr, n);
    // initializing the Hash Table
    int HT[SIZE] = {};
    for (int i = 0; i < n; i++)
    {
        Insert(HT, arr[i]);
    }
    cout << "Hash Table after quadratic probing is as follows : " << endl;
    display(HT, SIZE);

    return 0;
}


//example of secondary clustering:

// Given array: 
// 7 14 21 35 31 9
// Hash Table after quadratic probing is as follows :
// 7 14 35 31 9 0 0