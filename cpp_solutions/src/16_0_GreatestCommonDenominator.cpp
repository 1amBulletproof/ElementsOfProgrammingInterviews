/*
	Find the greatest common denominator of two numbers
	@author	Brandon Tarney
	@date	09/2019
	*/

#include <iostream>

using namespace std;

class GCD
{
	public:
		static const int findGCD(const int val1, const int val2);
};

const int GCD::findGCD(const int val1, const int val2)
{
	cout<<"val1"<<val1<<" val2"<<val2<<endl;
	int valDiff = 0;
	if (val1 == val2)
	{
		return (val1);
	}

	if (val1 > val2)
	{
		valDiff = val1 - val2;
		return (GCD::findGCD(valDiff, val2));
	}
	else
	{
		valDiff = val2 - val1;
		return (GCD::findGCD(valDiff, val1));
	}
}

int main()
{
	cout<<"Find GCD"<<endl;
	int val1 = 125;
	int val2 = 10;
	const int gcd = GCD::findGCD(121,11);
	cout<<"GCD of "<<val1<<" and "<<val2<<" is "<<gcd<<endl;
	return (0);
}
