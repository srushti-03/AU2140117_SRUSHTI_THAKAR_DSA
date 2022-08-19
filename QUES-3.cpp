

#include <iostream>
using namespace std;

// ques-3 .. function addup() that accepts a number and adds up all nubmers till that number
int addUp(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num + addUp(num - 1);
}
int main()
{
    cout << "enter any number: " << endl;
    int n;
    cin >> n;
    int ans = addUp(n);
    cout << ans << endl;
}

// //output:

// enter any number:
// 10
// 55
