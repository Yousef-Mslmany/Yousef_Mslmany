//This is a soultion to the Problem #16.
#include <iostream>
#include <string>
using namespace std;
string Read_Password()
{
    string Password;

        cout << "Please enter a 3-Letter Password (all capital)" << endl;
        cin >> Password;

    return Password;
};
bool Guess_Password(string Original_Password)
{
    string Word = "";int Counter = 1;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);
                cout << "Trial [" << Counter << "] : " << Word << endl;
                if (Word == Original_Password)
                {
                    cout << "Password is " << Word << endl;
                    cout << "Found after " << Counter << " Trial(s)" << endl;
                    return true;
                }
                Counter++;
                Word = "";
            }

        }
        cout << "****************************************\n";
    }

};
int main()
{
    Guess_Password(Read_Password());
}
