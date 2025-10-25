//This is a soultion to the Problem #6.
#include <iostream>
using namespace std;
struct strFullName
{
    string First_Name;
    string Last_Name;
};
strFullName Read_Full_Name()
{
    strFullName Info;

    cout << "Please Enter The First Name: ";
    cin >>Info.First_Name;
    cout << "Please Enter The Last Name: ";
    cin >> Info.Last_Name;

    return Info;
};
string Get_Full_Name(strFullName Info,bool Reversed)
{
    string Full_Name;
    if (Reversed)
        Full_Name = Info.Last_Name + " " + Info.First_Name;
    else
        Full_Name = Info.First_Name + " " + Info.Last_Name;

    return Full_Name;
};
void Print_Full_Name(string Full_Name)
{
    cout << "Your Name is: " << Full_Name << endl;
};
int main()
{
    Print_Full_Name(Get_Full_Name(Read_Full_Name(),1));
    cout << "End the Program.";
}
