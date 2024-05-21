/******************************************************
** Program: stalactites.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef STALACTITES_H
#define STALACTITES_H 

//Stalactites Interface
#include "event.h"

class Stalactites : public Event{ 
private:

public:
    /*********************************************************************
	** Function: Stalactites()
	** Description: constructor
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: Stalactites is constructed
	*********************************************************************/
    Stalactites();

    /*********************************************************************
	** Function: ~Stalactites()
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: any memory is deleted
	*********************************************************************/
    ~Stalactites();

    /*********************************************************************
	** Function: get_event_type
	** Description: returns S for stalactites event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: S is returned
	*********************************************************************/
    char get_event_type() const;

    /*********************************************************************
	** Function: percept()
	** Description: displays Stalactites percept
	** Parameters: none
	** Pre-Conditions: player is adjacent to Stalactites room
	** Post-Conditions: Message is displayed
	*********************************************************************/
    void percept() const;

    /*********************************************************************
	** Function: encounter()
	** Description: user has 50/50 chance of dying or surviving
	** Parameters: none
	** Pre-Conditions: user is in room with Stalactites
	** Post-Conditions: message is displayed and user is alive or dead
	*********************************************************************/
    bool encounter() const;

};

#endif
