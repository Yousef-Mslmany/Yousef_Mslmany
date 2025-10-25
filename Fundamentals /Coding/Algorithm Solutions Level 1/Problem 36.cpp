//This is a soultion to the Problem #36
#include <iostream>
using namespace std;
enum en_Operation_Type { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };
float Read_Number(string Message)
{
	float Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
};
en_Operation_Type Read_Op_Type()
{
	char OT = '+';
	cout << "Please enter Operation Type ( + , - , * , / )" << endl;
	cin >> OT;
	return (en_Operation_Type)OT;
};
float Calculate(float Number1,float Number2, en_Operation_Type Op_Type)
{
	
	switch (Op_Type)
	{
	case en_Operation_Type::Add:
		return Number1 + Number2;
	case en_Operation_Type::Subtract:
		return Number1 - Number2;
	case en_Operation_Type::Multiply:
		return Number1 * Number2;
	case en_Operation_Type::Divide:
		return Number1 / Number2;
	default:
		cout << "Wrong Operation";
	}
	
};

int main()
{
	float Number1 = Read_Number("Please enter the First Number: ");
	float Number2 = Read_Number("Please enter the second Number: ");
	en_Operation_Type OpType = Read_Op_Type();
	cout << "Result = " << Calculate(Number1, Number2, OpType) << endl;
	cout << "End the Program.";
}
 