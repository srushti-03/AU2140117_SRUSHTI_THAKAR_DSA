// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS
#include <iostream>
using namespace std;

// ques 7: Write a function IsPali( ) that accepts a string and returns True if it is a palindrome and returns
//  False it is not.
bool IsPali(string s, int i)
{
    if (i > s.size() / 2)
    {
        return true;
    }
    else
    {
        return (s[i] == s[s.size() - i - 1]) && IsPali(s, i + 1);
    }
}
int main()
{
    string s;

    cout << "enter any string: " << endl;
    getline(cin, s); // to input an entire string...
    bool ans = IsPali(s, 0);
    if (ans == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

// output:
//  enter any string:
//  madam
//  true