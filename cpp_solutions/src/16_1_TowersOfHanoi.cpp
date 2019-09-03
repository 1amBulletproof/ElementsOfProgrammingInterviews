/*
	Move the rings from one peg to another, using 2 aux pegs, never having larger pegs on top of smaller
	- Seems like if you have only the smallest or "1" ring to move, then simply move it
	- if you have 2 (or more?) pegs to move, then you must move the top to the third, move the one below to the 2nd, and then move the third one back to the top of the original stack! - it can then be moved to the desired peg
	@author	Brandon Tarney
	@date	09/2019
	*/

#include <iostream>

using namespace std;

class TowersOfHanoi
{
	public:
		static void transferNRings(const int numRings);
};

void TowersOfHanoi::transferNRings(const int numRings)
{
	//TODO
}

int main()
{
	cout<<"Print TowersOfHanoi"<<endl;
	return (0);
}
