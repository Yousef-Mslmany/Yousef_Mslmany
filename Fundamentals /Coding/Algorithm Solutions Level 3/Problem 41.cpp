
#include <string>
#include <iostream>
#include<vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter a character?\n";
	getline(cin, S1);
	return S1;
};

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;
	string delim = " ";
	short Pos = 0;
	string sWord;
	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != " ")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1 != " ")
	{
		vString.push_back(S1);
	}
	return vString;
};

string ReversWordsInString(string S1)
{
	vector <string> vString;
	string S2 = "";

	vString = SplitString(S1, " ");
	vector <string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		iter--;

		S2 = S2 + *iter + " ";
	}
	S2.substr(0, S2.length() - 1);
		return S2;
};

int main()
{
	string S1 = ReadString();
	cout << "\nString after reversing words:";
	cout << "\n" << ReversWordsInString(S1);

	return 0;
}