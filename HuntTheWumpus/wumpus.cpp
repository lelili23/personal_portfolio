/******************************************************
** Program: wumpus.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "wumpus.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
Wumpus::Wumpus() : Event("Wumpus"){}

Wumpus::~Wumpus(){}

char Wumpus::get_event_type() const {
        return 'W'; //returns W for Wumpus
}

void Wumpus::percept() const{
        //display Wumpus message
        cout << "You smell a terrible stench." << endl;
}

bool Wumpus::encounter() const{
        //display encounter message and player is dead
        cout << endl << "Uh oh! You woke up the Wumpus and got eaten. Game Over." << endl;
        return false;
}
