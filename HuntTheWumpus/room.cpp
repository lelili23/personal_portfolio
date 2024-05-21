/******************************************************
** Program: room.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "room.h"

using namespace std;

void Room::set_event(Event* new_event) {
	if (this->room != nullptr) { //check if an event already exists, and delete
		delete this->room;
	}
	this->room = new_event; //set event to room
}

Event* Room::get_event() const {
	return this->room; // return pointer to event
}

Room::~Room() {
	delete room;
	room = nullptr; 
}

