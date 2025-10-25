//This is a soultion the problem #35
#include <iostream>
using namespace std;
struct st_Piggy_Bank_Contenet
{
    int Penny;
    int Nickel;
    int Dime;
    int Quarter;
    int Dollar;
    int Total;
};
st_Piggy_Bank_Contenet Read_Pigge_Bank_Contenet()
{
    st_Piggy_Bank_Contenet Piggy_Bank_Contenet;
    cout << "This is a program to calculate the total pennies" << endl;
    cout << "Enter the Penny = ";
    cin >> Piggy_Bank_Contenet.Penny;

    cout << "Enter the Nickel = ";
    cin >> Piggy_Bank_Contenet.Nickel;

    cout << "Enter the Dime = ";
    cin >> Piggy_Bank_Contenet.Dime;

    cout << "Enter the Quarter = ";
    cin >> Piggy_Bank_Contenet.Quarter;

    cout << "Enter the Dollar = ";
    cin >> Piggy_Bank_Contenet.Dollar;

    return Piggy_Bank_Contenet;
};
int Calculate_Total_Pennies(st_Piggy_Bank_Contenet Piggy_Bank_Contenet)
{
    Piggy_Bank_Contenet.Nickel = 5 * Piggy_Bank_Contenet.Penny;
    Piggy_Bank_Contenet.Dime = 10 * Piggy_Bank_Contenet.Penny;
    Piggy_Bank_Contenet.Quarter = 25 * Piggy_Bank_Contenet.Penny;
    Piggy_Bank_Contenet.Dollar = 100 * Piggy_Bank_Contenet.Penny;
    Piggy_Bank_Contenet.Total = Piggy_Bank_Contenet.Penny + Piggy_Bank_Contenet.Nickel + Piggy_Bank_Contenet.Dime + Piggy_Bank_Contenet.Quarter + Piggy_Bank_Contenet.Dollar;
    return Piggy_Bank_Contenet.Total;
};
int main()
{
    int TotalPennies = Calculate_Total_Pennies(Read_Pigge_Bank_Contenet());
    cout << "Total Pennies = "<< TotalPennies << endl;
    cout << "Total Dollars = " << (float)TotalPennies / 100 << endl;
    cout << "End the program.";

    return 0;
}
