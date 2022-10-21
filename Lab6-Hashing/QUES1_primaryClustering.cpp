// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// explaining primary clustering in linear probing with an example.

#include <bits/stdc++.h>
#define SIZE 7 // defining size as 7

using namespace std;

int Hash(int key)
{
    return key % SIZE; // defining the hash function
}

int LinearProbe(int H[], int key)
{
    int index = Hash(key); // the linear probing function, used when there are collisions at a given position
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
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
        index = LinearProbe(H, key);
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

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } // displaying the hash table
    cout << endl;
}

int main()
{

    int A[] = {7,14,21,35,33};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Given array: " << endl;
    print(A, n);
    // initializing the Hash Table
    int HT[SIZE] = {};
    for (int i = 0; i < n; i++)
    {
        Insert(HT, A[i]);
    }
    cout << "Hash Table after linear probing is as follows : " << endl;
    print(HT, SIZE);

    return 0;
}

// primary clustering:

// Given array: 
// 7 14 21 35 33
// Hash Table after linear probing is as follows :
// 7 14 21 35 0 33 0