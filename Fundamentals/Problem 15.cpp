//This is soultion to problem #15
#include <iostream>
using namespace std;
void Read_Lengths_of_The_Rectangle(float& Length, float& Width)
{
    cout << "Please enter Length of the rectangle: ";
    cin >> Length;
    cout << "Please enter Width of the rectangle: ";
    cin >> Width;
};

float Rectangle_Area(float& Width, float& Length)
{
    float Area;
    Area = Length * Width;
    return Area;

};

void Print_Rectangle_Area(float Area)
{
    cout << "Area = Length * Width = " << Area << endl;
};

//This is a Program to calculate Rectangle Area.
int main()
{
    float Length, Width;
    Read_Lengths_of_The_Rectangle(Length, Width);
    Print_Rectangle_Area(Rectangle_Area(Width, Length));
    cout << "End the program.";
    return 0;
}
