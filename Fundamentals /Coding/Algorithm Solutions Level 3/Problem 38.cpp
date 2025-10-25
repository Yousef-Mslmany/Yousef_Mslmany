
#include <string>
#include <iostream>
#include<vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "String = ";
	getline(cin, S1);
	return S1;
};

string TrimLeft(string S1)
{

	for (int i = 0; S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - 1);
		}	
	}
	return "";
};

string TrimRight(string S1)
{

	for (int i = S1.length(); i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
};

string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}

int main()
{
	string S1 = "     Yousef Mslmany     ";
	cout << "\nString       =" << S1;
	cout << "\nTrim left  = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim       = " << Trim(S1);

	return 0;
}