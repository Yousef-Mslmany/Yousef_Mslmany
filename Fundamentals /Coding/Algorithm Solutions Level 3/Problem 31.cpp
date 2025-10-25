
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

char Readchar()
{
	char character;
	cout << "\nPlease Enter a character?\n";
	cin >> character;
	return character;
}
char InvertLetterCase(char ch1)
{
	return isupper(ch1) ? tolower(ch1) : toupper(ch1);
};


short CountLetters(string S1, char ch1, bool MatchCase = true)
{
	short Counter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == ch1)
				Counter++;
		}
		else
		{
			if (tolower(S1[i])== tolower(ch1))
				Counter++;
		}	
	}

	return Counter;
};

int main()
{
	string S1 = ReadString();
	char ch1 = Readchar();

	cout << "\nLetter '" << ch1 << "' count = " << CountLetters(S1, ch1);
	cout << "\nLetter '" << ch1 << "' Or '" << InvertLetterCase(ch1) << "' count = " << CountLetters(S1, ch1, false);

	system("pause>0");
}