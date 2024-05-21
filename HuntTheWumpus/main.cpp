/******************************************************
** Program: main.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

/*********************************************************************
	** Function: main()
	** Description: driver function creates instance of Game and runs
	** Parameters:none
	** Pre-Conditions:none
	** Post-Conditions: game is over
	*********************************************************************/
int main()
{
	//set the random seed
	srand(time(NULL));
	
	Game g;

	//Play game
	g.play_game();

	return 0;
}