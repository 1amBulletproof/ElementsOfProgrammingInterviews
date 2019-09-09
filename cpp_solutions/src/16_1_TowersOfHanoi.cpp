/*
	Move the rings from one peg to another, using 2 aux pegs, never having larger pegs on top of smaller
	- Seems like if you have only the smallest or "1" ring to move, then simply move it
	- if you have 2 (or more?) pegs to move, then you must move the top to the third, move the one below to the 2nd, and then move the third one back to the top of the original stack! - it can then be moved to the desired peg
	@author	Brandon Tarney
	@date	09/2019
	*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class TowersOfHanoi
{
	public:

		static void computeTowersHanoiSteps(const int numRings, vector< deque<int> > & pegs, int fromPeg, int toPeg, int usePeg);
};


void TowersOfHanoi::computeTowersHanoiSteps(const int numRings, vector< deque<int> > & pegs, int fromPeg, int toPeg, int usePeg)
{
	if (numRings > 0)
	{
		TowersOfHanoi::computeTowersHanoiSteps(numRings-1, pegs, fromPeg, usePeg, toPeg);
		pegs[toPeg].push_front(pegs[fromPeg].front());
		pegs[fromPeg].pop_front();
		cout<<"Move from peg "<<fromPeg<<" to peg " <<toPeg<<endl;
		TowersOfHanoi::computeTowersHanoiSteps(numRings-1, pegs, usePeg, toPeg, fromPeg);
	}
}



int main()
{
	cout<<"Print TowersOfHanoi"<<endl;
	const int numPegs = 3;
	const int numRings = 3;
	vector< deque<int> > pegs;
	for (int i = 0; i < numPegs; i++)
	{
		deque<int> aPeg;
		pegs.push_back( aPeg );
	}

	for (int i = numRings; i >= 1; --i)
	{
		pegs.front().push_back(i);
	}
	TowersOfHanoi::computeTowersHanoiSteps(numRings, pegs, 0, 2, 1);
	return (0);
}
