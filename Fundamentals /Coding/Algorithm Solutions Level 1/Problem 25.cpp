//This is a soultion to the Program #25
#include <iostream>
using namespace std;
int Read_Age()
{
    short Age;
    cout << "Please Enter Age between 18 and 45: " << endl;
    cin >> Age;
    return Age;
};
bool Validate_Number_In_Range(int Number, int From, int To)
{
    return (Number > From && Number < To);
};
int Read_Until_Age_Between(int From, int To)
{
    int Age;
    do
    {
        Age = Read_Age();
    } while (!Validate_Number_In_Range(Age, From, To));

    return Age;
};
void Print_Resulte(int Age)
{
    if (Validate_Number_In_Range(Age, 18, 45))
        cout << Age << " is a valid age \n";
    else
        cout << Age << " is unvalid age \n";
};
int main()
{
    Print_Resulte(Read_Until_Age_Between(18, 45));
    cout << "End the Program.";
}
