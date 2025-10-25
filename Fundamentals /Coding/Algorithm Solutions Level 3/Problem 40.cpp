
#include <string>
#include <iostream>
#include<vector>
using namespace std;

string  JoinString(vector <string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
};

string  JoinString(string arr[] ,int Length ,string Delim)
{
	string S1 = "";

	for (int i = 0; i < Length; i++)
	{
		S1 = S1 + arr[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
};

int main()
{
	vector<string> vString;
	vString = { "Yousef","Amjad","Ali","Mohammed","Alaa" };
	cout << "Vector after join:\n";
	cout << JoinString(vString, " ");

	string arrString[] = { "Yousef","Amjad","Ali","Mohammed","Alaa" };

	cout << "\n\nArray after join:\n";
	cout << JoinString(arrString, 5, " ");
	return 0;
}