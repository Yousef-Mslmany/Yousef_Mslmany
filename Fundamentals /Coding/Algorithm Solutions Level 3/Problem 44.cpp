
#include <string>
#include <iostream>
#include<vector>
using namespace std;

string RemoveAllPunctations(string S1)
{
	string S2 = "";
	for (int i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 = S2 + S1[i];
		}
	}
	return S2;
};


int main()
{
	string S1 = { "Welcome to Syria, Syria is a nice country; it's amazing." };
	cout << "Original string: \n" << S1;

	cout << "\n\nPunctations Removed:\n";
	cout << RemoveAllPunctations(S1);


}