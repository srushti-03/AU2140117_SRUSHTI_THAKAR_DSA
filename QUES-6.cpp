// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS
#include <iostream>
using namespace std;

// ques -6. hcf of two numbers:
int hcf(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return hcf(num2, num1 % num2);
    }
}
int main()
{
    cout << "enter any 2 numbers of your choice: " << endl;
    int a, b;
    cin >> a >> b;
    int ans = hcf(a, b);
    cout << "the hcf of the given numbers is :" << ans << endl;
}

// sample output:

// enter any 2 numbers of your choice:
// 12 4
// the hcf of the given numbers is :4
