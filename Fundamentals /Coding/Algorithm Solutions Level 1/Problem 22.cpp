//This is to soultion the problem #22
#include <iostream>
using namespace std;
void Read_Triangle_Data(float& A, float& B)
{
    cout << "Please Enter the first triangle rib length: ";
    cin >> A;

    cout << "Please Enter the second triangle rib length: ";
    cin >> B;
};
float Circle_Area_By_I_Triangle(float A, float B)
{
    float  Area;
   const float PI = 3.14;
    Area = floor(PI * (pow(B, 2)) / 4 * (2 * A - B) / (2 * A + B));
    return Area;
};
void Print_Area(float Area)
{
    cout << "Area is = " << Area << endl;
};
int main()
{
    float A, B, Area;
    Read_Triangle_Data(A, B);
    Print_Area(Circle_Area_By_I_Triangle(A, B));
    cout << "End the program.";

    return 0;
}

