// AU2140117 SRUSHTI THAKAR
// LAB 6 HASHING
//  QUES 8
// DATA STRUCTURES AND ALGORITHMS

#include <bits/stdc++.h>
using namespace std;

class HT_2D // defining the class HT_2D
{
public:
    int rows, columns;
    int crash1, crash2, crash3, crash4; // defining the 4 crashed servers
    vector<vector<int>> hashtable;

    HT_2D(int r, int c)
    {
        this->rows = r;
        this->columns = c;
        hashtable = vector<vector<int>>(rows, vector<int>(columns, 0)); // similar to a 2d array with rows and columns ( but with vectors)
    }

    void Hashing_old_servers()
    {
        cout << "The default servers when roll numbers of 126 students are added are as follows: " << endl;

        int key = 1;
        for (int i = 0; i < 127; i++)
        {

            int j;
            for (int j = 0; j < rows; j++)
            {
                int placetoInsert = (key + j) % rows;
                for (int k = 0; k <= columns; k++)

                {

                    if (hashtable[placetoInsert][k] == 0) // as the default value was 0
                    {
                        hashtable[placetoInsert][k] = key; // assigning the value of the element at the appropriate position
                        // cout << "The index on which the element " << element_value << " is added is " << "(" << (element_value + j) % row << "," << k << ")" << endl;
                        break;
                    }
                }
                break;
            }
            if (j == rows)
                cout << "Overflow error, the 2d array is full! " << endl;

            key++;
        }
    };

    void crashed_server(int crash1, int crash2, int crash3, int crash4)
    {
        this->crash1 = crash1;
        this->crash2 = crash2;
        this->crash3 = crash3;
        this->crash4 = crash4;
    };

    void Hashing_New_Servers()
    {
        cout << "The servers after 4 servers got crashed are as follows: " << endl;

        int key = 1;
        int index;
        for (int i = 1; i < 127; i++)
        {
            index = key % 17;

            if (index == crash1 || index == crash2 || index == crash3 | index == crash4)
            {
                for (int j = 0; j < 13; j++)
                {
                    int a = (key + j) % 13;

                    if (a == crash1 || a == crash2 || a == crash3 || a == crash4)
                        continue;
                    else
                    // checking if the servers are defective or not, if the server has crashed hash it again
                    {
                        hashtable[a].push_back(key);

                        break;
                    }
                }
            }

            key++;
        }
    };

    void Hash2D_print_Crash()
    {
        for (int i = 0; i < rows; i++)
        {

            cout << "Server number " << i << " --> ";

            for (auto vec : hashtable[i])
            {
                if (i == crash1 || i == crash2 || i == crash3 || i == crash4)
                {
                    cout << "this server is defected ! ";
                    break;
                }
                else
                {
                    if (vec == 0)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << vec << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    };
    ;

    void Hash2D_print()
    {
        for (int i = 0; i < rows; i++)
        {

            cout << "Server number " << i << "-->  ";

            for (auto vec : hashtable[i])
            {

                if (vec == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << vec << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    };
};

int main()
{

    // sample test case

    HT_2D default_server1(17, 8);                 // setting the value of rows and columns of the 2d array
    default_server1.Hashing_old_servers();        // hashing the default servers
    default_server1.Hash2D_print();               // printing the hash table for the default values of servers
    default_server1.crashed_server(2,15,10,7); // setting any 4 out of 17 servers as defective
    default_server1.Hashing_New_Servers();        // hashing the new servers(that is 17-4=13 servers)
    default_server1.Hash2D_print_Crash();         // printing the hash table for the new values of servers

    return 0;
}








// sample output:



// The default servers when roll numbers of 126 students are added are as follows: 
// Server number 0-->  17 34 51 68 85 102 119
// Server number 1-->  1 18 35 52 69 86 103 120
// Server number 2-->  2 19 36 53 70 87 104 121
// Server number 3-->  3 20 37 54 71 88 105 122
// Server number 4-->  4 21 38 55 72 89 106 123
// Server number 5-->  5 22 39 56 73 90 107 124
// Server number 6-->  6 23 40 57 74 91 108 125
// Server number 7-->  7 24 41 58 75 92 109 126
// Server number 8-->  8 25 42 59 76 93 110 127 
// Server number 9-->  9 26 43 60 77 94 111
// Server number 10-->  10 27 44 61 78 95 112
// Server number 11-->  11 28 45 62 79 96 113
// Server number 12-->  12 29 46 63 80 97 114
// Server number 13-->  13 30 47 64 81 98 115
// Server number 14-->  14 31 48 65 82 99 116
// Server number 15-->  15 32 49 66 83 100 117
// Server number 16-->  16 33 50 67 84 101 118

// The servers after 4 servers got crashed are as follows:
// Server number 0 --> 17 34 51 68 85 102 119  78 104 117
// Server number 1 --> 1 18 35 52 69 86 103 120 27 53 66 92 
// Server number 2 --> this server is defected !
// Server number 3 --> 3 20 37 54 71 88 105 122 2 15 41
// Server number 4 --> 4 21 38 55 72 89 106 123 95 121
// Server number 5 --> 5 22 39 56 73 90 107 124 44 70 83 109
// Server number 6 --> 6 23 40 57 74 91 108 125 19 32 58
// Server number 7 --> this server is defected !
// Server number 8 --> 8 25 42 59 76 93 110 127 7 112
// Server number 9 --> 9 26 43 60 77 94 111  61 87 100 126
// Server number 10 --> this server is defected !
// Server number 11 --> 11 28 45 62 79 96 113  10 24 36 49 75 
// Server number 12 --> 12 29 46 63 80 97 114
// Server number 13 --> 13 30 47 64 81 98 115
// Server number 14 --> 14 31 48 65 82 99 116
// Server number 15 --> this server is defected !
// Server number 16 --> 16 33 50 67 84 101 118