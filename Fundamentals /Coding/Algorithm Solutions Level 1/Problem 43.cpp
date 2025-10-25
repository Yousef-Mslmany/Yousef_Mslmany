//This is a Soultion the Problems #43
#include <iostream>
using namespace std;
struct strTaskDuration
{
    int Number_Of_Days;
    int Number_Of_Hours;
    int Number_Of_Minutes;
    int Number_Of_Seconds;
};
int Read_Positive_Number(string Message)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < 0);
    return Number;
};
strTaskDuration Second_To_Task_Duration(int Total_Seconds)
{
    strTaskDuration TaskDuration;
    const int Second_Per_Days = 24 * 60 * 60;
    const int Second_Per_Hours = 60 * 60;
    const int Second_Per_Minutes = 60;

    int Remainder = 0;
    TaskDuration.Number_Of_Days = floor(Total_Seconds / Second_Per_Days);
    Remainder = Total_Seconds % Second_Per_Days;
    TaskDuration.Number_Of_Hours = floor(Remainder / Second_Per_Hours);
    Remainder = Remainder % Second_Per_Hours;
    TaskDuration.Number_Of_Minutes = floor(Remainder / Second_Per_Minutes);
    Remainder = Remainder % Second_Per_Minutes;
    TaskDuration.Number_Of_Seconds = Remainder;

    return TaskDuration;
};
void Print_Global_Time(strTaskDuration TaskDuration)
{
    cout << "The time of Days , Hours , Minutes , and Seconds =  \n";
    cout << TaskDuration.Number_Of_Days << ":"
        << TaskDuration.Number_Of_Hours << ":"
        << TaskDuration.Number_Of_Minutes << ":"
        << TaskDuration.Number_Of_Seconds << "\n";
};
int main()
{ 
    int Total_Seconds = Read_Positive_Number("Please Enter the Total Of Secouds? ");
    Print_Global_Time(Second_To_Task_Duration(Total_Seconds));
    cout << "End the program.";

    return 0;
}
