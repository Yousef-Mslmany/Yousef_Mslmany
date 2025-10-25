//This is a solution to the Problem #33. 
#include <iostream>
using namespace std;
int Read_Number_In_Rang(int From,int To)
{
    int Grade;
    do
    {
        cout << "Please Enter a grade between 0 and 100: ";
        cin >> Grade;
    } while (Grade > To || Grade < From);

    return Grade;
};
char Get_Grade_Letter(int Grade)
{
    if (Grade > 90 && Grade <= 100)
        return 'A';
    else if (Grade > 80 && Grade <= 90)
        return 'B';
    else if (Grade > 70 && Grade <= 80)
        return 'C';
    else if (Grade > 60 && Grade <= 70)
        return 'D';
    else if (Grade > 50 && Grade <= 60)
        return 'E';
    else
        return 'F';
};
int main()
{
    cout << "Your Score is: " << Get_Grade_Letter(Read_Number_In_Rang(0,100)) << endl;
    cout << "End the Program.";
}
