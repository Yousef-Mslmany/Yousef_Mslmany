
#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your string?\n";
	getline(cin, S1);
	return S1;
}

char InvertCaseCharacter(char Character)
{
	return isupper(Character) ? tolower(Character) : toupper(Character);
};

string InvertAllStringLetterCase(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertCaseCharacter(S1[i]);
	}
	return S1;
};

int main()
{
	string S1 = ReadString();

	cout << "\nString after inverting All letters case: \n";
	S1 = InvertAllStringLetterCase(S1);
	cout << S1 << endl;

	system("pause>0");
}