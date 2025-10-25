//This is a soultion the Problem #47
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
float Number_of_Months(float Loan_Amonut, float Monthly_payment)
{
    return (float)Loan_Amonut / Monthly_payment;
};
int main()
{
    float Loan_Amonut = Read_Number("Please Enter a Lona Amonut : ");
    float Monthly_payment = Read_Number("Please Enter a Monthly_payment : ");
    cout << "You need to pay the amount : " << Number_of_Months(Loan_Amonut, Monthly_payment) << " Months"<<endl;
    cout << "End the Program";
     
    return 0;
}
