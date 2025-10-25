//This is a soultion to the Problem #15.
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
void Print_Letter_Pattern(int Number)
{
    for (int i = 65; i <= 65 + Number - 1; i++)
    {
        for (int j = 65; j <= i; j++)
        {
            cout << (char)i;
        }
        cout << endl;
    }

};
int main()
{
    Print_Letter_Pattern(Read_Positive_Number("Please enter a positive number: "));
}
