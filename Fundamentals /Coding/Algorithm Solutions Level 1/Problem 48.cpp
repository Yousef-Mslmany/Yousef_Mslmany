//This is a soultion the Problem #48
#include <iostream>
using namespace std;
int Read_Number(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
};
float Money_You_Will_Pay(float Lona_Amount, float Number_of_Month)
{
    return (float) Lona_Amount / Number_of_Month;

};
int main()
{
    float Lona_Amount = Read_Number("Please Enter Lona Amount :");
    float How_Many_Months = Read_Number("Please Enter Number_of_Month :");
    cout << "The money you will pay each month = " << Money_You_Will_Pay(Lona_Amount, How_Many_Months) <<" Doller"<< endl;
    cout << "End the Program.";
    return 0;
}
