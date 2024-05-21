/******************************************************
** Program: gold.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

//Gold Implementation
Gold::Gold() : Event("Gold"){}

Gold::~Gold(){}

char Gold::get_event_type() const {
        return 'G'; //return G for Gold event
}

void Gold::percept() const{
        //display Gold percept
        cout << "You see a glimmer nearby." << endl;
}

bool Gold::encounter() const{
        //display Gold encounter and set gold to picked up
        cout << "You have picked up the Gold! Now go back to where you started to finish the game." << endl << endl;
        return true;
}
