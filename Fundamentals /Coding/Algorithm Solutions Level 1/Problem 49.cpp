//This is a soultion to the Problem #49
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
    do
    {
        Pin_Code = Read_PIN_Code();
        if (Pin_Code == "1234")
        {
            return 1;
        }
        else
        {
            cout << "Wrong PIN\n";
            cout << system("color 4F");
        }
    } while (Pin_Code != "1234");
    return 0;
};
int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "Your account balance is " << 7500 << "\n";
    };
    return 0;
    cout << "End the Program.";
}
