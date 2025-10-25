//This is a soultion to the Problem #24
#include <iostream>
using namespace std;
float Read_Total_Sales()
{
    float Total_Sales;
    cout << "Please Enter Total Sales: ";
    cin >> Total_Sales;
    return Total_Sales;
};
float Get_comission_Percentage(float FU_Total_Sales)
{
    float Result;
    if (FU_Total_Sales > 1000000)
    {
        return 0.01;
    }
    else if (FU_Total_Sales < 1000000 && FU_Total_Sales>500000)
    {
        return 0.02;
    }
    else if (FU_Total_Sales < 500000 && FU_Total_Sales>100000)
    {
        return 0.03;
    }
    else if (FU_Total_Sales < 100000 && FU_Total_Sales>50000)
    {
        return 0.05;
    }
    else
    {
        return 0.00;
    }
};
float Calculate_Total_Comission(float Total_Sales)
{
    return Get_comission_Percentage(Total_Sales) * Total_Sales;
};
int main()
{
    float Total_Sales = Read_Total_Sales();
    cout << "comission Percentage = " << Get_comission_Percentage(Total_Sales) << endl;
    cout << "Total Comission = " << Calculate_Total_Comission(Total_Sales) << endl;
    cout<<Calculate_Total_Comission(Get_comission_Percentage(Read_Total_Sales()));
    cout << "End the Program.";
}
