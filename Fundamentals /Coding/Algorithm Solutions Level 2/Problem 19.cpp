//This is a soultion to the Problem #19.
#include <iostream>
#include <string>
using namespace std;
int Rendom_Number(int From, int To)
{

    int Rand_Number = rand() % (To - From + 1) + From;
    return Rand_Number;

}
int main()
{
    srand((unsigned)time(NULL));

    cout << Rendom_Number(1, 10) << endl;
    cout << Rendom_Number(1, 10) << endl;
    cout << Rendom_Number(1, 10) << endl;

    return 0;
}
