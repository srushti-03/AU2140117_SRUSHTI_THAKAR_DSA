// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// ques-2 (part-A): quadratic probing

#include <bits/stdc++.h>
#define SIZE 37              //defining SIZE as 37

using namespace std;
 
int Hash(int key){
    return key % SIZE;                 //defining the hash function
}
 
int QuadraticProbe(int H[], int key){
    int index = Hash(key);                   // the quadratic probing function, used when there are collisions at a given position
    int i = 0;
    while (H[(index+i*i) % SIZE] != 0){
        i++;
    }
    return (index + i) % SIZE;
}
 
void Insert(int H[], int key){
    int index = Hash(key);                   //inserting into the hash table
 
    if (H[index] != 0){
        index = QuadraticProbe(H, key);
    }
    H[index] = key;
}
 
int Search(int H[], int key){
    int index = Hash(key);
    int i = 0;
    while (H[(index+i) % SIZE] != key){
        i++;                                       //searching the key in the hash table
        if (H[(index + i) % SIZE] == 0){
            return -1;
        }
    }
    cout<<key;
    return (index + i) % SIZE;
}

void print(int arr[], int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }                                              //displaying the hash table
    cout<<endl;
    }
 
 
int main() {
 
    int arr[] = {133, 88, 92, 221, 174};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array: "<<endl;
    print(arr, n);
    // initializing the Hash Table
    int HT[SIZE] = {};
    for (int i=0; i<n; i++){
        Insert(HT, arr[i]);
    }
    cout<<"Hash Table after quadratic probing is as follows : "<<endl;
    print(HT, SIZE);


    int index = Search(HT, 100);
    cout <<"100 is found at index:" << index << endl;
 
    int index1 = Search(HT, 133);
    
    cout << " is found at index:" << index1 << endl;
 
    int index2 = Search(HT, 174);
    
    cout << " is found at index: " << index2 << endl;
 
    return 0;
}



//sample output:


// Given array: 
// 133 88 92 221 174 
// Hash Table after quadratic probing is as follows : 
// 0 0 0 0 0 0 0 0 0 0 0 0 0 0 88 0 0 0 92 0 0 0 133 0 0 0 174 0 0 0 0 0 0 0 0 0 221 
// 100 is found at index:-1
// 133 is found at index:22
// 174 is found at index: 26


