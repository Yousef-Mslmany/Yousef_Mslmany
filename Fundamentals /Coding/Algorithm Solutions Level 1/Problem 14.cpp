//This is program to soultion a problem #14
#include <iostream>
using namespace std;

void Read_Numbers(int& Number1, int& Number2)
{ 
    cout << "Please enter Number1: ";
    cin >> Number1;
    cout << "Please enter Number2: ";
    cin >> Number2;
};

void Swap(int& Number1, int& Number2)
{
    int  Temp;
    Temp = Number1;
    Number1 = Number2;
    Number2 = Temp;
};

void Print_Number(int Number1, int Number2)
{
    cout << "Number1: " << Number1 << endl;
    cout << "Number2: " << Number2 << endl;
};

int main()
{
    int Number1;
    int Number2;
    Read_Numbers(Number1, Number2);
    Print_Number(Number1, Number2);
    Swap(Number1, Number2);
    Print_Number(Number1, Number2);
    cout << "End tne program";
    return 0;
}

