/******************************************************
** Program: event.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "event.h"

#include <iostream>

using namespace std;

//Event Implementation
Event::Event(string name) : name(name) {}

Event::~Event() {}

