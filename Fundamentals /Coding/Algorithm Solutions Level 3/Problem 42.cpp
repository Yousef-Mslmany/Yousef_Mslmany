
#include <string>
#include <iostream>
#include<vector>
using namespace std;

string ReplaceFunction(string S1, string WordToReplace, string ToReplace)
{
	short Pos = S1.find(WordToReplace);
	while (Pos != std::string::npos)
	{
		S1.replace(Pos, WordToReplace.length(), ToReplace);
		Pos = S1.find(WordToReplace);
	}
	return S1;
};


int main()
{
	string S1 = { "Welcome to Syria, Syria is a nice country" };
	string WordToReplace = { "Syria" };
	string ToReplace = { "Jordan" };

	cout << "Orginal String:\n" << S1;
	cout << "\n\nString after replace:\n";
	cout << ReplaceFunction(S1, WordToReplace, ToReplace);
}