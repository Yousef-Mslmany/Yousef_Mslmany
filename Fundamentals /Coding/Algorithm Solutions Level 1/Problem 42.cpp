//This is a soultion the Problem #42
#include <iostream>
using namespace std;
struct strTaskDuration
{
    int Days;
    int Hours;
    int Minutes;
    int Seconds;
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
strTaskDuration Read_Task_Duration()
{
    strTaskDuration TaskDuration;
    TaskDuration.Days = Read_Positive_Number("Please Enter the number of Days : ");
    TaskDuration.Hours = Read_Positive_Number("Please Enter the number of Hours : ");
    TaskDuration.Minutes = Read_Positive_Number("Please Enter the number of Minutes : ");
    TaskDuration.Seconds = Read_Positive_Number("Please Enter the number of Seconds : ");
    return TaskDuration;
};
int Task_Duration_In_Seconds(strTaskDuration TaskDuration)
{
    int  Total = 0;

    TaskDuration.Days = TaskDuration.Days * 60 * 60 * 24;
    TaskDuration.Hours = TaskDuration.Hours * 60 * 60;
    TaskDuration.Minutes = TaskDuration.Minutes * 60;
    TaskDuration.Seconds = TaskDuration.Seconds * 1;

    Total = TaskDuration.Days + TaskDuration.Hours + TaskDuration.Minutes + TaskDuration.Seconds;

    return Total;
};

int main()
{
    cout << "Task Duration In Seconds: " << Task_Duration_In_Seconds(Read_Task_Duration())<<" seconds " << endl;
    cout << "End the Program.";
    return 0;

}
