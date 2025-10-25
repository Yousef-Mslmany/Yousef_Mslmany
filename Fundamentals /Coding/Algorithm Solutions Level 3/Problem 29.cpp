
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

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
	short Counter = 0;

	if (WhatToCount==enWhatToCount::All)
	{
		return S1.length();
	}

	for (int i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			Counter++;
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			Counter++;
	}
	return Counter;
};

short CountCapitalLetters(string S1)
{
	short CountCapital = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			CountCapital++;
		}
	}
	return CountCapital;
};

short CountSamllLetters(string S1)
{
	short CountSamll = 0;
	for (int i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			CountSamll++;
		}
	}
	return CountSamll;
};

int main()
{
	string S1 = ReadString();

	cout << "\nString length = " << CountLetters(S1) << endl;
	cout << "Capital letters count = " << CountLetters(S1, enWhatToCount::CapitalLetters) << endl;
	cout << "Small letters count = " << CountLetters(S1, enWhatToCount::SmallLetters) << endl;

	cout << "\n\nMethod 2:\n";

	cout << "\nString length = " << S1.length() << endl;
	cout << "Capital letters count = " << CountCapitalLetters(S1) << endl;
	cout << "Small letters count = " << CountSamllLetters(S1) << endl;

	system("pause>0");
}