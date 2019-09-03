/*
   Convert to string from int & vice versa
   - key is to convert one digit at a time implicitly (as "char()") or via subtracting '0'
	@author brandon tarney
	@date	09/2019
	*/

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int stringToInt(string & val)
{
	int valInt = 0;
	for (int i = val[0] == '-'? 1 : 0; 
			i < val.size(); i++)
	{
		valInt = (valInt * 10) + (val[i] - '0');
	}
	if (val[0] == '-')
	{
		valInt = 0 - valInt;
	}

	return (valInt);
}

string intToString(int val)
{
	string valStr;
	const char baseDigit = '0';

	bool isNegative = false;
	if (val < 0)
	{
		isNegative = true;
	}

	do 
	{
		char charVal = (char) (baseDigit + abs((val % 10)));
		val = val / 10;
		valStr.insert(0, &charVal);
	} while (val != 0);

	if (isNegative)
	{
		const char negativeChar = '-';
		valStr.insert(0, &negativeChar);
	}
	return (valStr);
}

int main()
{
	int input = 42;
	string valStr = intToString(input);
	cout<<"converted "<<input<<" to "<<valStr<<endl;
	input = -91;
	valStr = intToString(input);
	cout<<"converted "<<input<<" to "<<valStr<<endl;

	string inputStr("42");
	int valInt = stringToInt(inputStr);
	cout<<"converted "<<inputStr<<" to "<<valInt<<endl;
	inputStr = "-9";
	valInt = stringToInt(inputStr);
	cout<<"converted "<<inputStr<<" to "<<valInt<<endl;
	return 0 ;
}

