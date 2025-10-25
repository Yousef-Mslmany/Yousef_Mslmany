//This is a soulation the problem #18
#include <iostream>
using namespace std;
float Read_Radius()
{
    float Radius;
    cout << "This Programe to calculate The circle area." << endl;
    cout << "Please enter Radius: ";
    cin >> Radius;
    return Radius;
};

float Circle_Area(float Radius)
{
    float Area;
   const float PI = 3.14159;
    Area = ceil(PI * pow(Radius, 2));
    return Area;
};

void Print_Area(float Area)
{
    cout << "The Area is = " << Area << endl;
};

//This is a Program to calculate circle area.
int main()
{
    float Area, Radius ;
    Print_Area(Circle_Area(Read_Radius()));
    cout << "End the Program.";
    return 0;
}
  