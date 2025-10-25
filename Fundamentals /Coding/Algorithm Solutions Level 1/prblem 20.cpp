//This is soultion a problem #20
#include <iostream>
using namespace std;
float Read_Diameter()
{
    float Square_Area;
    cout << "This Programe to calculate The circle area." << endl;
    cout << "Please enter Square_Area: ";
    cin >> Square_Area;
    return Square_Area;
};
float Circle_Area_In_Scribed_In_Square(float Square_Area)
{
    float Area;

     const float  PI = 3.14159;
    Area = ceil(PI * pow(Square_Area, 2) / 4);

    return Area;
};
void Print_Area(float Area)
{
    cout << "Area is :" << Area << endl;
};
int main()
{
    Print_Area(Circle_Area_In_Scribed_In_Square(Read_Diameter()));
    cout << "End the program.";

    return 0;
}
