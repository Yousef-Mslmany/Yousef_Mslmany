//This is a soultion to the problem #16
#include <iostream>
using namespace std; 
void Read_Numbers(float& Diagonal, float& Side_Length)
{

    cout << "Please enter Diagonal: ";
    cin >> Diagonal;
    cout << "Please enter Number2: ";
    cin >> Side_Length;

};
float Rectangle_Area(float Diagonal, float Side_Length)
{
    float Area;
    Area = Diagonal * (sqrt(pow(Side_Length, 2) - pow(Diagonal, 2)));
    return Area;
};
void Print_Area(float Area)
{
    cout << "The Area is = " << Area << endl;
};
int main()
{
    float Diagonal, Side_Length;
    Read_Numbers(Diagonal, Side_Length);
    Print_Area(Rectangle_Area(Diagonal, Side_Length));
    cout << "End the program.";
    return 0;
}
