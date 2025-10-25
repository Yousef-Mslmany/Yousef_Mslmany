//This is a soultion to the Problem #4
#include <iostream>
using namespace std;
struct stInfo
{
	short Age;
	bool Has_Driving_License;
};
stInfo Read_Info()
{
	stInfo Info;
	cout << "Please Enter Your Age: ";
	cin >> Info.Age;
	cout << "Do you have driver license: ";
	cin >> Info.Has_Driving_License;
	return Info;
};
bool Is_Accepted(stInfo Info)
{
	return (Info.Age > 21 && Info.Has_Driving_License);
};
void Print_Info(stInfo Info)
{
	if (Is_Accepted(Info))
	{
		cout << "Hired" << endl;
    }
	else
	{
		cout << "Rejected" << endl;
	}
};
int main()
{
	Print_Info(Read_Info());
	
	cout << "End the Program.";
}
