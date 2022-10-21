// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// Q1(a). Using Linear Probing, create two hashtables (arrays) of sizes (a) 17 and (b) 37.
//  Add the following numbers to both the hashtables (The numbers are written into the array ):

// 133, 88, 92, 221, 174
// Now, check if these numbers are in the hashtables or not.

// 100, 133, 174
// (b) Create a list of numbers (this list should be unique for each student) to demonstrate primary clustering.

#include <bits/stdc++.h>
#define SIZE 17 // defining size as 17

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

    int arr[] = {133, 88, 92, 221, 174};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array: " << endl;
    display(arr, n);
    // initializing the Hash Table
    int HT[SIZE] = {};
    for (int i = 0; i < n; i++)
    {
        Insert(HT, arr[i]);
    }
    cout << "Hash Table after linear probing is as follows : " << endl;
    display(HT, SIZE);

    int index = Search(HT, 100);
    cout << "100 is found at index:" << index << endl;

    int index1 = Search(HT, 133);

    cout << " is found at index:" << index1 << endl;

    int index2 = Search(HT, 174);

    cout << " is found at index: " << index2 << endl;

    return 0;
}

// sample output:

// Given array:
// 133 88 92 221 174
// Hash Table is as follows :
// 221 0 0 88 174 0 0 92 0 0 0 0 0 0 133 0 0
// 100 is found at index:-1
// 133 is found at index:14
// 174 is found at index: 4

// element found at index -1 , means that the element is not present in the array.
