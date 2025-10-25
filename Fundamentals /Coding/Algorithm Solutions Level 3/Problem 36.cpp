
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

int CountWords(string S1)
{
	short Count = 0;
	string delim = " ";
	short Pos = 0;
	string sWord;
	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != " ")
		{
			Count++;
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1 != " ")
	{
		Count++;
	}
	return Count;
};

int main()
{
	string S1;

	S1 = ReadString();
	cout << "\nThe number of word in your string is: ";

	cout << CountWords(S1);

	return 0;
}