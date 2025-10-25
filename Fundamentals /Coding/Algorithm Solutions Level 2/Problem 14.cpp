//This is a soultion to the Problem #14.
#include <iostream>
#include <string>
using namespace std;
int Read_Positive_Number(string Message)
{
    float Number;
    do
    {

        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

    return Number;
};
void Print_Inverted_Letter_Pattern(int Number)
{
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        for (int j = 1; j <= Number; j++)
        {
            cout << (char)i;
        }
        Number--;
        cout << endl;
    }

};
int main()
{
    Print_Inverted_Letter_Pattern(Read_Positive_Number("Please enter a positive number"));
}
