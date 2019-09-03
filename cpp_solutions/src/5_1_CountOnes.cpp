/*
   This program will count the number of 1's in a binary number
   @author	Brandon Tarney
	@date	09/2019
	*/


#include <iostream>

using namespace std;

unsigned int countOnes(unsigned int testVar)
{
	unsigned int numberOfOnes = 0;
	while (testVar != 0)
	{
		//cout<<"testing "<<testVar<<endl;
		//AND the value with 1 and then shift it to the right
		numberOfOnes += testVar & 1;
		testVar = testVar>>1;
	}
	return (numberOfOnes);
}

int main()
{
	for (unsigned int testVar = 0; testVar < 8; testVar++)
	{
		cout<<"testVar("<<testVar<<"), numberOfOnes("<<countOnes(testVar)<<")"<<endl;
	}
	return 0;
}


