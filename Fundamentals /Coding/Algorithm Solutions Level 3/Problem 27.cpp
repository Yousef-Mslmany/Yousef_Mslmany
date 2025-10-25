
#include <string>
#include <iostream>
using namespace std;

char ReadCharacter()
{
	char Character;
	cout << "Please Enter a Character?\n";
	cin >> Character;
	return Character;
}

char InvertCaseCharacter(char Character)
{
	return isupper(Character) ? tolower(Character) : toupper(Character);
};

int main()
{
	char Character = ReadCharacter();

	cout << "\nChar after inverting case: \n";
	Character = InvertCaseCharacter(Character);
	cout << Character << endl;

	system("pause>0");
}