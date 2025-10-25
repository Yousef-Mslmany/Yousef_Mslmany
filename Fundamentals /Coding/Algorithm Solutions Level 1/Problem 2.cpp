//This is a soultion to the Problem #2
#include <iostream>
#include <string>
using namespace std;
string ReadYourName()
{
    string YourName;
    cout << "Please Enter Your Name : ";
    getline(cin, YourName);
    return YourName;
};
void PrintYourName(string YourName)
{
    cout << "Your name is :" << YourName << endl;
};

//This is a program to Print Your Name.
int main()
{
    PrintYourName(ReadYourName());
    return 0;

}
