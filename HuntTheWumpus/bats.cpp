/******************************************************
** Program: bats.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "bats.h"


using namespace std;

//Bats Implementation
Bats::Bats() : Event("Bats"){}

Bats::~Bats(){}

char Bats::get_event_type() const {
    return 'B'; // return Bat event letter
}

void Bats::percept() const{
    // display Bat percept
    cout << "You hear wings flapping." << endl;
}

bool Bats::encounter() const{
    // display Bat encounter and send confused move signal
    cout << endl << "Oh no! You have walked into a bat cave! You feel dizzy." << endl;
    return true;
}
