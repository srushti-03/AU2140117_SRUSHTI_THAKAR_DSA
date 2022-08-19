// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS
#include <iostream>
using namespace std;

// ques -8. Write a function reverse( ) that accepts a string and reverses it.
void reverse(string s)
{
    if (s.size() == 0)
    {

        {
            return;
        }

        reverse(s.substr(1));
        cout << s[0];
    }
}
int main()
{

    string s;
    cout << "enter any string : " << endl;
    getline(cin, s);

    reverse(s);
}

// output :

//     enter any string : srushti
//                        ithsurs
