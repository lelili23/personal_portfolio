/******************************************************
** Program: room.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

class Room
{
private: 
	Event *room = nullptr;
public:
	/*********************************************************************
	** Function: set_event()
	** Description: assign event to room
	** Parameters: pointer to an Event
	** Pre-Conditions: none
	** Post-Conditions: Room contains the new event
	*********************************************************************/
    void set_event(Event *new_event);

	/*********************************************************************
	** Function: get_event()
	** Description: returns event type
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions:pointer to event is returned
	*********************************************************************/
	Event* get_event() const;

	/*********************************************************************
	** Function: ~Room()
	** Description: deconstructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: memory contained in room is deleted
	*********************************************************************/
	~Room();

};

#endif