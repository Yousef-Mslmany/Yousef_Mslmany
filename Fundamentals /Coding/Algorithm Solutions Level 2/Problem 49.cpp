//This is a soultion to the Problem #48.
#include <iostream>
#include <string>
#include<Math.h>
using namespace std;
float Read_Number()
{
    float Number;
    cout << "\nPlease enter a float number?\n";
    cin >> Number;
    return Number;
};
float Get_Fraction_Part(float Number)
{
    return Number - (int)Number;
};
int My_Ceil(float Number)
{

    if (abs(Get_Fraction_Part(Number)) > 0)
    {
        if (Number >= 0)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
    {
        return Number;
    }

};
int main()
{
    float Number = Read_Number();
    cout << "My ceil Result : " << My_Ceil(Number) << endl;
    cout << "C++ ceil Result : " << ceil(Number) << endl;

    return 0;
}