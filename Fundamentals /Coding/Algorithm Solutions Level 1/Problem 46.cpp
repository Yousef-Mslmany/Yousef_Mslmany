//This is a soultion to the Problem #46.
#include <iostream>
using namespace std;
void Print_Letters_A_to_Z()
{
	int i = 65;
	for (i = 65; i <= 90; i++)
	{
		cout << char(i) << endl;
	}
};
int main()
{
	Print_Letters_A_to_Z();
	cout << "End the Program.";
}
