//AU2140117 SRUSHTI THAKAR
//DATA STRUCTURES AND ALGORITHMS
//LAB 6
//HASHING

//ques-3)  Using Double Hashing, create one hashtable (array) with M = 17, P = 11.
// Add the following numbers to the hashtables (The numbers are written into the array ):
// 133, 88, 92, 221, 174
// Now, check if these numbers are in the hashtables or not.
// 100, 133, 174


#include <bits/stdc++.h>
#define SIZE 17 // defining size as 17
#define PRIME 11  //defining prime as 19

using namespace std;

int Hash(int key)
{
    return key % SIZE; // defining the hash function
}



int PrimeHash(int key){
    return PRIME - (key % PRIME);          //defining the primeHash function
}
 
int DoubleHash(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(Hash(index) + i * PrimeHash(index)) % SIZE] != 0){
        i++;                                                              //defining the doubleHash function
    }
    return (index + i * PrimeHash(index)) % SIZE;
}


void InsertKey(int H[], int key)
{
    int index = Hash(key); // inserting into the hash table

    if (H[index] != 0)
    {
        index = DoubleHash(H, key);
    }
    H[index] = key;
}

int SearchKey(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(Hash(index) + i * PrimeHash(index)) % SIZE] != key){         //searching for the key
        i++;
        if (H[(Hash(index) + i * PrimeHash(index)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(index) + i * PrimeHash(index)) % SIZE;
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
    cout << "displaying the array inputted: " << endl;
    display(arr, n);
    // initializing the Hash Table
    int HT[SIZE] = {};
    for (int i = 0; i < n; i++)
    {
        InsertKey(HT, arr[i]);
    }
    cout << "Hash Table after double hashing is as follows : " << endl;
    display(HT, SIZE);

    int index = SearchKey(HT, 100);
    cout << "100 is found at index:" << index << endl;

    int index1 = SearchKey(HT, 133);

    cout << "133 is found at index:" << index1 << endl;

    int index2 = SearchKey(HT, 174);

    cout << "174 is found at index: " << index2 << endl;

    return 0;
}



//sample output:


// displaying the array inputted: 
// 133 88 92 221 174
// Hash Table after double hashing is as follows :
// 221 0 0 88 174 0 0 92 0 0 0 0 0 0 133 0 0
// 100 is found at index:-1
// 133 is found at index:14
// 174 is found at index: 4