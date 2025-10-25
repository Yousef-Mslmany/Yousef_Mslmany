
#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter a character?\n";
	getline(cin, S1);
	return S1;
};

void PrintEachWordInString(string S1)
{
	string delim = " ";
	cout << "\nYour string words are:\n\n";
	short Pos = 0;
	string sWord;
	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != " ")
		{
			cout << sWord << endl;
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1!=" ")
	{
		cout << S1 << endl;
	}
};

int main()
{
	PrintEachWordInString(ReadString());

	return 0;
}