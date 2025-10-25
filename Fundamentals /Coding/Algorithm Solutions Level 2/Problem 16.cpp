//This is a soultion to the Problem #16.
#include <iostream>
#include <string>
using namespace std;
void Print_Words_From_AAA_TO_ZZZ()
{
    string Word = "";
    for (int i = 65; i <= 90 ; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                cout << Word << endl;
                Word = "";
            }

        }
        cout << "****************************************\n";
    }

};
int main()
{
    Print_Words_From_AAA_TO_ZZZ();
}
