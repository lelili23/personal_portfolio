/******************************************************
** Program: bats.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef BATS_H
#define BATS_H 

//Bats Interface
#include "event.h"

class Bats : public Event{ 
private:

public:
    /*********************************************************************
	** Function: Bats()
	** Description: constructor
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: Bats is constructed
	*********************************************************************/
    Bats();

    /*********************************************************************
	** Function: ~Bats()
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: any memory is deleted
	*********************************************************************/
    ~Bats();

    /*********************************************************************
	** Function: get_event_type
	** Description: returns B for bat event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: B is returned
	*********************************************************************/
    char get_event_type() const;

    /*********************************************************************
	** Function: percept()
	** Description: displays Bat percept
	** Parameters: none
	** Pre-Conditions: player is adjacent to Bats room
	** Post-Conditions: Message is displayed
	*********************************************************************/
    void percept() const;

    /*********************************************************************
	** Function: encounter()
	** Description: makes user have confused moves
	** Parameters: none
	** Pre-Conditions: user is in room with bats
	** Post-Conditions: message is displayed and user has 5 confused moves
	*********************************************************************/
    bool encounter() const;

       
};

#endif