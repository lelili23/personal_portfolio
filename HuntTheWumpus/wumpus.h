/******************************************************
** Program: wumpus.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H 

//Wumpus Interface
#include "event.h"

class Wumpus : public Event{ 
private:

public:
    /*********************************************************************
	** Function: Wumpus()
	** Description: constructor
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: Wumpus is constructed
	*********************************************************************/
    Wumpus();

    /*********************************************************************
	** Function: ~Wumpus()
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: any memory is deleted
	*********************************************************************/
    ~Wumpus();

    /*********************************************************************
	** Function: get_event_type
	** Description: returns W for Wumpus event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: W is returned
	*********************************************************************/
    char get_event_type() const;

    /*********************************************************************
	** Function: percept()
	** Description: displays Wumpus percept
	** Parameters: none
	** Pre-Conditions: player is adjacent to Wumpus room
	** Post-Conditions: Message is displayed
	*********************************************************************/
    void percept() const;

    /*********************************************************************
	** Function: encounter()
	** Description: makes user have confused moves
	** Parameters: none
	** Pre-Conditions: user is in room with Wumpus
	** Post-Conditions: message is displayed and user has 5 confused moves
	*********************************************************************/
    bool encounter() const;    
};

#endif