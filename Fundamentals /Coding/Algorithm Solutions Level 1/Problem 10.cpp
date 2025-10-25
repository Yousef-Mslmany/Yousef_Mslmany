//This is Soultion a problem #10
#include <iostream>
using namespace std;
struct strMarks
{
    int Mark1;
    int Mark2;
    int Mark3;
};
strMarks Read_Number()
{
    strMarks  Marks;
    cout << "Please Enter the Mark1: ";
    cin >> Marks.Mark1;
    cout << "Please Enter the Mark2: ";
    cin >> Marks.Mark2;
    cout << "Please Enter the Mark3: ";
    cin >> Marks.Mark3;
    return Marks;
};
float Average(strMarks Marks)
{
    return (float)(Marks.Mark1 + Marks.Mark2 + Marks.Mark3) / 3;
};
void Print_Your_Average(float Average)
{
    cout << "Your Average is: " << Average << endl;
};
int main()
{
    Print_Your_Average(Average(Read_Number()));
    cout << "End the Program";
}
