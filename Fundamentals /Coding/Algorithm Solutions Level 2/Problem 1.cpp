//This is a soultion to Problem #1.
#include <iostream>
using namespace std;
void Print_Table_Header()
{
	cout << "\n\n\t\t\tMultipliaction Table From 1 To 10\n\n";
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";
	}
	cout << "\n___________________________________________________________________________________\n";
};
string Coulum_Sperator(int i)
{
	if (i == 10)
		return "   |";
	else
		return "    |";
};
void Print_Multipliaction_Table()
{
	Print_Table_Header();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << Coulum_Sperator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j<<"\t";
		}
		cout << endl;
	}
};
int main()
{
	Print_Multipliaction_Table();
}
