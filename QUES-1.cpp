// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS

// QUES -1 finding factorial of a given number:

#include <iostream>
#include <cassert>
using namespace std;

int factorial(int num)

{

    if (num == 0 or num == 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
}
int main()
{
    cout << "enter any number: " << endl;
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << "the factorial of " << n << " is " << ans << endl;
}

// sample output:

// enter any number:
// 9
// the factorial of 9 is 362880