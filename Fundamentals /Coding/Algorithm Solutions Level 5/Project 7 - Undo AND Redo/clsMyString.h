#pragma once
#include <iostream>
#include <stack>

using namespace std;

class clsMyString
{
private:
	string _Value = "";
	stack <string> _Undo;
	stack <string> _Redo;
public:

	void Set(string Value)
	{
		_Undo.push(_Value);
		_Value = Value;
	}

	string Get()
	{
		return _Value;
	}

	_declspec(property(get = Get, put = Set)) string Value;

	void Undo()
	{
		if (_Undo.empty()) return;
		
		_Redo.push(_Value);
		_Value = _Undo.top();
		_Undo.pop();
	}

	void Redo()
	{
		if (_Redo.empty()) return;

		_Undo.push(_Value);
		_Value = _Redo.top();
		_Redo.pop();
	}
};


