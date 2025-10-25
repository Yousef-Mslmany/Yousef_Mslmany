//This is a soultion to the Problem #37.
#include <iostream>
#include<string>
using namespace std;
float Read_Number(string Message)
{
    float Number;
    cout << Message << endl;
    cin >> Number;
    return Number;
};
int Sum_Number()
{

    int Sum = 0, Number = 0, Counter = 1;
    do
    {
        Number = Read_Number("Please Enter a Number " + to_string(Counter));

        if (Number==-99)
        {
            break;
        }

        Sum = Sum + Number;
        Counter++;

    } while (Number!=-99);

    return Sum;
};
int main()
{
    cout << "The Result = " << Sum_Number() << endl;
    cout << "The End Program.";
}
