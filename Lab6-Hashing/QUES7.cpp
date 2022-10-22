// AU2140117 SRUSHTI THAKAR
// DATA STRUCTURES AND ALGORITHMS
// LAB 6
// HASHING

// ques-7: create a 2D array for hashing numbers:


#include <bits/stdc++.h>
using namespace std;

// 2d hash function represents a hashing table in the form of a 2D array:

void Hash(int arr1[], int arr2[][10], int n)
{ // key is the element inserted in the hash table
    int key;
    for (int i = 0; i < n; i++)
    {

        key = arr1[i] % 10;
        if (arr2[key][0] == 0)
        {
            arr2[key][0] = arr1[i];
        }
        else
        {

            for (int j = 1; j < 10; j++)
            {
                if (arr2[key][j] == 0)
                {
                    arr2[key][j] = arr1[i];
                    break;
                }
            }
        }
    }

    cout << "the 2d array hash table is as follows: " << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        { // displaying the hash table
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
}
void searchKey(int arr1[], int arr2[][10], int n, int element)
{
    int a;
    a = element % 10;
    if (arr2[a][0] == element)
    {
        cout << "the element was found at index: " << endl;
        cout <<"row: "<<a<< " "<<"column: " << 0;
    }
    else
    {
        for (int j = 1; j < 10; j++)
        {
            if (arr2[a][j] == element)
            {
                cout << "the element was found at index: " << endl; // searching for the key in the 2D array hash table
                cout << "row: " <<a<< " "<< "column: " << j << endl;
                break;
            }
        }
        cout << "the element is not found in the array! " << endl;

        // here 0 means that no element is present at that particular index in the hash
    }
}

int main()
{

    //inputting elements into the array

    int n, element;
    cout << "enter the number of elements you want to add in the array: " << endl;
    cin >> n;
    cout << "enter the array elements : " << endl;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int arr2[10][10];
    for (int i = 0; i < 10; i++)
    { // enter elements you want to add into the hash table
        for (int j = 0; j < 10; j++)
        {
            arr2[i][j] = 0;
            //initializing all elements of the array to 0
        }
    }
    Hash(arr1, arr2, n);
    cout << "enter the key to be searched: " << endl;
    cin >> element;
    searchKey(arr1, arr2, n, element);
    return 0;
}

// sample output:


// enter the number of elements you want to add in the array:
// 5 
// enter the array elements : 
// 12 10 34 7 56
// the 2d array hash table is as follows: 
// 10 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 12 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 34 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 56 0 0 0 0 0 0 0 0 0 
// 7 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 
// enter the key to be searched:
// 34
// the element was found at index:  
// row: 4 column: 0

