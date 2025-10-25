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
int My_Floor(float Number)
{
    if (Number >= 0)
        return int(Number);
    else
        return int(Number) - 1;

};
int main()
{
    float Number = Read_Number();
    cout << "My Round Result : " << My_Floor(Number) << endl;
    cout << "C++ Round Result : " << floor(Number) << endl;

    return 0;
}