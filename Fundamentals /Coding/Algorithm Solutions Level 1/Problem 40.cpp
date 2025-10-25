//This is a soultion the program #40
#include <iostream>
using namespace std;
float Read_Positive_Number(string Message)
{
    cout << "This is program to calculate BillValue after add Service_fee and Sales_Tax it." << endl;
    float Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);

    return Number;
};
float Total_Bill_After_Service_And_Tax(float Total_Bill)
{
    Total_Bill = Total_Bill * 1.1;
    Total_Bill = Total_Bill * 1.16;
    return Total_Bill;
};
int main()
{
    float Total_Bill = Read_Positive_Number("Please Enter Total Bill = ");
    cout << "Total Bill = " << Total_Bill << endl;
    cout << "Total Bill After Service Fee and Sales Tax = " << Total_Bill_After_Service_And_Tax(Total_Bill) << endl;
   
    cout << "End the program.";
    
    return 0;
}
