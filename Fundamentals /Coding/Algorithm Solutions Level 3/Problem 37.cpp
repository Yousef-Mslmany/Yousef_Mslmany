
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

vector <string> Split(string S1, string Delim)
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

int main()
{
	vector<string> vString;
	vString = Split(ReadString(), " ");

	cout << "Tokens = " << vString.size() << endl;
	for (string& s : vString)
	{
		cout << s << endl;
	}

	return 0;
}