
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

short CountLetters(string S1, char ch1)
{
	short Counter = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i]== ch1)
		{
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

	system("pause>0");
}