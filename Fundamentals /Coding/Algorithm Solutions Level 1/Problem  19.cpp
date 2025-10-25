//This is a Soultion to the Problem #19
#include <iostream>
using namespace std;
float Read_Diameter()
{
    float Diameter;
    cout << "This Programe to calculate The circle area." << endl;
    cout << "Please enter Radius: ";
    cin >> Diameter;
    return Diameter;
};
float Circle_Area_By_Diameter(float Diameter)
{
    float Area;

   const float PI = 3.14159;
    Area = (PI * pow(Diameter, 2)) / 4;

    return Area;
};
void Print_Area(float Area)
{
    cout << "Area is :" << Area << endl;
};
int main()
{
    float Diameter, Area;
    Print_Area(Circle_Area_By_Diameter(Read_Diameter()));
    cout << "End The Program.";

    return 0;
}
