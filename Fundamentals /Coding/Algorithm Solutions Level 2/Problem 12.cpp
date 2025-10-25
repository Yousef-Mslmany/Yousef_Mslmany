//This is a soultion to the Problem #11.
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
void Print_Inverted_Number_Pattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }

};
int main()
{
    Print_Inverted_Number_Pattern(Read_Positive_Number("Please enter a positive number"));
}
