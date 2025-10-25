//This is a soultion to the Problem #8
#include <iostream>
using namespace std;
enum en_Pass_Fail { Pass = 1, Fail = 0 };
int Read_Mark()
{
	float Mark;
	cout << "Please Enter the Number: ";
	cin >> Mark;
	return Mark;
};
en_Pass_Fail Chack_Mark(int Mark)
{
	if (Mark >= 50)
		return en_Pass_Fail::Pass;
	else
		return en_Pass_Fail::Fail;

};
void Your_Result(int Mark)
{
	if (Chack_Mark(Mark) == en_Pass_Fail::Pass)
		cout << "Your Passed" << endl;
	else
		cout << "Your Faild" << endl;
	
};
int main()
{
	Your_Result(Read_Mark());
	cout << "End the Program.";
	return 0;
}
