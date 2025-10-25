//This is a soultion to a Problem #17
#include <iostream>
using namespace std;
void Read_Numbers(float& Height, float& Base_Length)
{
    cout << "This Programe to calculate The Area triangle." << endl;
    cout << "Please enter Height: ";
    cin >> Height;
    cout << "Please enter Base Length: ";
    cin >> Base_Length;

};

float Triangle_Area(float Height, float Base_Length)
{
   return  (0.5 * Base_Length) * Height;
};

void Print_Area(float Area)
{
    cout << "The Area is = " << Area << endl;
};

int main()
{
    float Height, Base_Length;
    Read_Numbers(Height, Base_Length);
    Print_Area(Triangle_Area(Height, Base_Length));
    cout << "End The Program.";

}
