/******************************************************
** Program: stalactites.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "stalactites.h"

#include <iostream>

using namespace std;

//Stalactites Implementation
Stalactites::Stalactites() : Event("Stalactites"){}

Stalactites::~Stalactites() {}

char Stalactites::get_event_type() const {
   return 'S'; //return S for stalactites
}

void Stalactites::percept() const{
   //display stalactites percept
   cout << "You hear water dripping." << endl;
}

bool Stalactites::encounter() const{
   //generate 50/50 chance that user dies 
   int chance = rand() % 2;
   if (chance == 0) {
        cout << "Game over. Stalactites fell on you." << endl;
        return false;
   } else {
        cout << "Lucky! You entered a room with stalactites, but they didn't fall." << endl;
        return true;
   }
}