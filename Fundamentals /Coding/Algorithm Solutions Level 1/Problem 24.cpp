//This is a soultion to the Program #24
#include <iostream>
using namespace std;
int Read_Age()
{
    short Age;
    cout << "Please Enter your Age: " << endl;
    cin >> Age;
    return Age;
};
bool Validate_Number_In_Range(int Number, int From, int To)
{
    return (Number > From && Number < To);
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
    Print_Resulte(Read_Age());
    cout << "End the Program.";
}
 