/******************************************************
** Program: event.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef EVENT_H
#define EVENT_H 

#include <iostream>
using namespace std;

class Event
{

protected:
	string name;

public:
	/*********************************************************************
	** Function: Event()
	** Description: constructor
	** Parameters: name
	** Pre-Conditions: none
	** Post-Conditions: Event is constructed
	*********************************************************************/
	Event(string name);

	/*********************************************************************
	** Function: ~Event()
	** Description: destructor
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: deletes memory 
	*********************************************************************/
	virtual ~Event();

	/*********************************************************************
	** Function: get_event_type()
	** Description: virtual function that will return letter of Event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: event letter returned
	*********************************************************************/
	virtual char get_event_type() const = 0; 

	/*********************************************************************
	** Function: percept()
	** Description: virtual function, will print out percept message
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: percept message is displayed
	*********************************************************************/
	virtual void percept() const = 0;

	/*********************************************************************
	** Function: encounter()
	** Description:virtual funciton, will handle encounter for event
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: event activity will be handled
	*********************************************************************/
	virtual bool encounter() const = 0;	
};
#endif