//This is a soultion the problem #39
#include <iostream>
using namespace std;
float Read_Positive_Number(string Message)
{
    float Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number<0);

    return Number;
};
int Calculate_Remainder(float TotalBill, float CashPaid)
{
    
   return  (CashPaid - TotalBill);
};
int main()
{
    float Total_Bill = Read_Positive_Number("Plese Enter Total Bill : ");
    float Cash_Paid = Read_Positive_Number("Plese Enter CashPaid : ");

    cout << "Total Bill = " << Total_Bill << endl;
    cout << "Cash_Paid = " << Cash_Paid << endl;
    cout << "***************************\n";

    cout<<"Remainder = "<< Calculate_Remainder(Total_Bill, Cash_Paid) << endl << endl;
    cout << "End the Program";
    return 0;
}
