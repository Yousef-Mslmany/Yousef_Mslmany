//This is a soultion to the problem #32
#include <iostream>
using namespace std;
float Read_Pow()
{
    float Pow;
    cout << "Please Enter the exponent : ";
    cin >> Pow;
    return Pow;
};
float Read_Number()
{
    float Number;
    cout << "Please Enter the number: ";
    cin >> Number;
    return Number;
};
float Power_Any_Number(float Number, float Pow)
{
    float  Result;
    Result = pow(Number, Pow);
    return Result;
};
int main()
{
    cout <<"Result = "<< Power_Any_Number(Read_Number(), Read_Pow());
    cout << "\n End the program.";


}
