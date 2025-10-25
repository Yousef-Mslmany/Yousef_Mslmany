//This is a soultion to the Problem #46.
#include <iostream>
#include <string>
#include<Math.h>
using namespace std;
int Read_Number()
{
    int Number;
    cout << "\nPlease enter a number?\n";
    cin >> Number;
    return Number;
};
int My_abs(int Number)
{
    if (Number < 0)
        Number = Number * -1;
    else
        Number = Number;

    return Number;
};
int main()
{
    float Number = Read_Number();
    cout << "My abs Result : " << My_abs(Number) << endl;
    cout << "C++ abs Result : " << abs(Number) << endl;

    return 0;
}