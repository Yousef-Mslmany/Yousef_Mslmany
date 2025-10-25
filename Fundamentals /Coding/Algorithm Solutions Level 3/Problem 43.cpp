
#include <string>
#include <iostream>
#include<vector>
using namespace std;

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

string  JoinString(vector <string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
};

string LowerAllString(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
};

string ReplaceWordInStringUsingSplit(string S1, string WordToReplace ,string ToReplace, bool MatchCase = true)
{
	vector<string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == WordToReplace)
					s = ToReplace;
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(WordToReplace))
				{
					s = ToReplace; 
				}
			}
		}
		return JoinString(vString, " ");
};


int main()
{
	string S1 = { "Welcome to Syria, Syria is a nice country" };
	string WordToReplace = { "Syria" };
	string ToReplace = { "USA" };

	cout << "Orginal String:\n" << S1;
	cout << "\n\nRepalce with match case:\n";
	cout << ReplaceWordInStringUsingSplit(S1, WordToReplace,ToReplace);

	cout << "\n\nRepalce with dont match case:\n";
	cout << ReplaceWordInStringUsingSplit(S1, WordToReplace, ToReplace, false);
}