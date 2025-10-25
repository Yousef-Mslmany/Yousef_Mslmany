//This is a soultion to the Problem #48.
#include <iostream>
#include <string>
#include<Math.h>
using namespace std;
float Read_Number()
{
    float Number;
    cout << "\nPlease enter a number?\n";
    cin >> Number;
    return Number;
};
int My_Sqrt(float Number)
{
    return pow(Number, 0.5);
};
int main()
{
    float Number = Read_Number();
    cout << "My Sqrt Result : " << My_Sqrt(Number) << endl;
    cout << "C++ Sqrt Result : " << sqrt(Number) << endl;

    return 0;
}