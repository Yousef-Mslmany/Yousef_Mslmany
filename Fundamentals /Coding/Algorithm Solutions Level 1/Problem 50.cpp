//This is a soultion to the Problem #50
#include <iostream>
using namespace std;
string Read_PIN_Code()
{
    string PIN;
    cout << "Please enter PIN Code \n";
    cin >> PIN;
    return PIN;
};
bool Login()
{
    string Pin_Code;
    int Counter = 3;
    do
    {
        Counter--;
        Pin_Code = Read_PIN_Code();
        if (Pin_Code == "1234")
        {
            return 1;
        }
        else
        {
            cout << system("color 4F");
            cout << "Wrong PIN, you have "<< Counter <<" more tries\n";
        }
    } while (Counter>=1 && Pin_Code != "1234");
    return 0;
};
int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "Your account balance is " << 7500 << "\n";
    }
    else
    {
        cout << "Your card blocked call the bank for help.\n";
    }
    return 0;
    cout << "End the Program.";
}
