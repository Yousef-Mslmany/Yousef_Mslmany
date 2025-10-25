//This is a soultion to the Problem #4.
#include <iostream>
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
bool Is_Prefect_Number(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum = Sum + i;
        }
    }
    return Number == Sum;
};
void Print_Prefect_Number_From_1_To_Number(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        if (Is_Prefect_Number(i))
        {
            cout << i << endl;
        }
    }

};
int main()
{
    Print_Prefect_Number_From_1_To_Number(Read_Positive_Number("Please enter a positive number : "));
}
