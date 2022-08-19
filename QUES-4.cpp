// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS
#include <iostream>
using namespace std;

// ques-4: fibonacci series:Write a function fib( ) that accepts a number n and outputs the nth number in the Fibonacci
// sequence.

int fib(int n)
{
    if (n == 1 or n == 2)
    {
        return n - 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    cout << "enter any number: " << endl;
    int n;
    cin >> n;
    int ans = fib(n);
    cout << "the answer is: " << ans << endl;
}

// output:

// enter any number:
// 5
// the answer is: 3
