
#include <string>
#include <iostream>
using namespace std;

char Readchar()
{
	char character;
	cout << "Please Enter a character?\n";
	cin >> character;
	return character;
}

bool IsAVowel(char character)
{
	character = tolower(character);
	return (character == 'a' || character == 'e' || character == 'o' || character == 'i' || character == 'u');
};


int main()
{
	char ch1 = Readchar();
    
	if (IsAVowel(ch1))
		cout << "\nYES letter '" << ch1 << "' is vowel";
	else
		cout << "\nNO letter '" << ch1 << "' is vowel";

	system("pause>0");
}