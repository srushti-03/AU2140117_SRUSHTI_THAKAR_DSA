// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// Q4. Create two hashtables (arrays) of size 17 and 37,such that each hashtable is an array of bits

#include <bits/stdc++.h>
#define SIZE 17 // defining size as 17

using namespace std;

int Hash(int key)
{ // defining the hash function
    return key % SIZE;
}

int LinearProbe(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)
    {
        i++; // defining the linear probe function
    }
    return (index + i) % SIZE;
}

void InsertKey(int H[], int key)
{
    int index = Hash(key);

    if (H[index] != 0)
    { // inserting keys into the hash table
        index = LinearProbe(H, key);
    }
    H[index] = 1;
}

int SearchKey(int H[], int key)
{
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 1)
    { // searching keys in the hash table
        i++;
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
    cout << "Given array is as follows : " << endl;
    display(arr, n);

    int HT[SIZE] = {};
    for (int i = 0; i < n; i++)
    {
        InsertKey(HT, arr[i]);
    }
    cout << "Hash Table: " << endl;
    display(HT, SIZE);

    int num = SearchKey(HT, 100);
    cout << "100 found at index : " << num << endl;

    num = SearchKey(HT, 133);
    cout << " found at index : " << num << endl;

    num = SearchKey(HT, 174);
    cout << " found at index : " << num << endl;

    return 0;
}

// sample output:

// Given array:
// 133 88 92 221 174
// Hash Table:
// 1 0 0 1 1 0 0 1 0 0 0 0 0 0 1 0 0
// 100 found at index : -1
// 133 found at index : 14
// 174 found at index : 4

// as it is an array of bits, we will get 1 wherever the key is present