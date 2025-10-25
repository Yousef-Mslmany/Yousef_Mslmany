//This is a soultion to program #21
#include <iostream>
using namespace std;
float Read_Diameter()
{
    float circumference_of_a_circle;
    cout << "This Programe to calculate The circle area along the circumference." << endl;
    cout << "Please enter circumference_of_a_circle: ";
    cin >> circumference_of_a_circle;
    return circumference_of_a_circle;
};
float Circale_Area_Along_The_Circumference(float circumference_of_a_circle)
{
    float Area;

   const float PI = 3.14;
    Area = floor(pow(circumference_of_a_circle, 2) / (4 * PI));

    return Area;

};
void Print_Area(float Area)
{
    cout << "Area is = " << Area << endl;
};
int main()
{
    Print_Area(Circale_Area_Along_The_Circumference(Read_Diameter()));
    cout << "End the program.";
    return 0;
}
