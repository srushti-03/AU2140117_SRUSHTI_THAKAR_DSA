// AU2140117 SRUSHTI THAKAR LAB -1 DATA STRUCTURES AND ALGORITHMS

// ques 2... find the output:

#include <iostream>
using namespace std;

void fourth();

void third();
void second();

void first();

void first()
{
    second();
    cout << "I am the first" << endl;
}
void second()
{
    third();
    cout << "I am the second" << endl;
}

void third()
{
    fourth();
    cout << "I am the third" << endl;
}
void fourth()
{
    cout << "I am the fourth" << endl;
}
int main()
{
    first();
    return 0;
}

//  //output:

//  I am the fourth
// I am the third
// I am the second
// I am the first
