//This is a soultion to the problem #23
#include <iostream>
#include <cmath> 
using namespace std;
void Read_Triangle_Data(float& A, float& B, float& C)
{
    cout << "Please Enter the lengths of the sides of the triangle:" << endl;
    cout << "A = ";
    cin >> A;

    cout << "B = ";
    cin >> B;

    cout << "C = ";
    cin >> C;
};
float Circle_Area_By_A_Triangle(float FU_A, float FU_B, float FU_C)
{ 
    float Area, PI, P, Root_Solution;

    PI = 3.14;
    P = (FU_A + FU_B + FU_C) / 2;
    Root_Solution = sqrt(P * (P - FU_A) * (P - FU_B) * (P - FU_C));
    Area = PI * pow((FU_A * FU_B * FU_C) / (4 * Root_Solution), 2);

    return Area;
};
void Print_Result(float Area)
{
    cout << "Area = " << round(Area) << endl;
};
int main()
{
    float A, B, C ;
    Read_Triangle_Data(A, B, C);
    Print_Result(Circle_Area_By_A_Triangle(A, B, C));
    cout << "End the program.";
    return 0;
}
