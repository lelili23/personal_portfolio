/******************************************************
** Program: gold.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef GOLD_H
#define GOLD_H 

//Gold Interface
#include "event.h"

class Gold : public Event{ 
private:

public:
    /*********************************************************************
	** Function: BaGoldts()
	** Description: constructor
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: Gold is constructed
	*********************************************************************/
    Gold();

    /*********************************************************************
	** Function: ~Gold()
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: any memory is deleted
	*********************************************************************/
    ~Gold();

    /*********************************************************************
	** Function: get_event_type
	** Description: returns G for gold event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: G is returned
	*********************************************************************/
    char get_event_type() const;

    /*********************************************************************
	** Function: percept()
	** Description: displays Gold percept
	** Parameters: none
	** Pre-Conditions: player is adjacent to Gold room
	** Post-Conditions: Message is displayed
	*********************************************************************/
    void percept() const;

    /*********************************************************************
	** Function: encounter()
	** Description: makes user pick up gold
	** Parameters: none
	** Pre-Conditions: user is in room with Gold
	** Post-Conditions: message is displayed and user picks up gold
	*********************************************************************/
    bool encounter() const; 
};

#endif