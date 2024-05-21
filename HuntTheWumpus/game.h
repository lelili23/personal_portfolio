/******************************************************
** Program: game.h
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game {
private:
	vector<vector<Room>> grid;
	int rows; 			//length of the board
	int columns;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not
	int pos_x;
	int pos_y;
	int wumpus_x;
	int wumpus_y;
	bool wumpus_alive;
	bool player_alive;
	bool have_gold;
	int inital_x;
	int inital_y;
	int confused_moves;

public:

	/*********************************************************************
	** Function: Game()
	** Description: Game constructor
	** Parameters:none
	** Pre-Conditions:none
	** Post-Conditions:instance of Game is created
	*********************************************************************/
	Game();

	/*********************************************************************
	** Function: ~Game()
	** Description: Game deconstructor
	** Parameters: none
	** Pre-Conditions: Game instance is going out of bound
	** Post-Conditions: any memory is deleted
	*********************************************************************/
	~Game();
	
	/*********************************************************************
	** Function: set_up()
	** Description: Sets up grid and inserts events
	** Parameters: length, width of grid
	** Pre-Conditions: user entered desired sizes
	** Post-Conditions: grid is resized and events are randomly inserted
	*********************************************************************/
	void set_up(int, int);

	/*********************************************************************
	** Function: insert_event()
	** Description: Randomly inserts events into an empty room
	** Parameters: pointer to an Event
	** Pre-Conditions: grid has been created and player is placed
	** Post-Conditions: event is placed into empty room
	*********************************************************************/
	void insert_event(Event* e);

	/*********************************************************************
	** Function: display_game()
	** Description: prints out the grid
	** Parameters: none
	** Pre-Conditions: new turn began
	** Post-Conditions: grid is displayed, with events if debug is on
	** NOTE: this function is past the line limit (18 lines), but it has
	** already been split into another function and there's not another
	** way to split it up more that will function well with the loops
	*********************************************************************/
	void display_game();

	/*********************************************************************
	** Function: print_debug
	** Description: prints out characters if debug is on
	** Parameters:none
	** Pre-Conditions: none
	** Post-Conditions: event character is printed if debug is on
	*********************************************************************/
	void print_debug(int, int);

	/*********************************************************************
	** Function: check_win
	** Description: checks if game should be over or continue
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: game either continues or ends
	*********************************************************************/
	bool check_win() const;

	/*********************************************************************
	** Function: get_dir()
	** Description: gets the user direction mobe
	** Parameters: none
	** Pre-Conditions: grid is displayed
	** Post-Conditions: user entered a valid direction
	*********************************************************************/
	char get_dir();

	/*********************************************************************
	** Function: wumpus_move()
	** Description: moves wumpus to empty room
	** Parameters:none
	** Pre-Conditions:user missed arrow shot
	** Post-Conditions: wumpus moves to an empty room or stays
	*********************************************************************/
	void wumpus_move();

	/*********************************************************************
	** Function: fire_arrow()
	** Description: fires arrow in direction to see if Wumpus is there
	** Parameters: none
	** Pre-Conditions: user chose direction and has remaining arrows
	** Post-Conditions: arrow is decremeneted
	** NOTE: this function is past limit (20), but it only handles firing
	** arrow and to split it up into 4 seperate functions for each direction
	** would be tedious as each function would only contain 3 lines each 
	** and the original function still fits on the display screen
	*********************************************************************/
	void fire_arrow();

	/*********************************************************************
	** Function: move_up()
	** Description: moves player up
	** Parameters:none
	** Pre-Conditions:player chose W 
	** Post-Conditions: players position is changed
	*********************************************************************/
	void move_up();

	/*********************************************************************
	** Function: move_down()
	** Description: moves player down
	** Parameters:none
	** Pre-Conditions:player chose S
	** Post-Conditions: players position is changed
	*********************************************************************/
	void move_down();

	/*********************************************************************
	** Function: move_left()
	** Description: moves player left
	** Parameters:none
	** Pre-Conditions:player chose A 
	** Post-Conditions: players position is changed
	*********************************************************************/
	void move_left();

	/*********************************************************************
	** Function: move_right()
	** Description: moves player right
	** Parameters:none
	** Pre-Conditions:player chose D 
	** Post-Conditions: players position is changed
	*********************************************************************/
	void move_right();

	/*********************************************************************
	** Function:move()
	** Description:either shoots arrow or moves player
	** Parameters: c- direction user inputted
	** Pre-Conditions: user chose move for turn
	** Post-Conditions: arrow is shot or player is moved
	*********************************************************************/
	void move(char);

	/*********************************************************************
	** Function:get_input()
	** Description:gets input for player's move
	** Parameters:none
	** Pre-Conditions:none
	** Post-Conditions:player chosen valid move
	*********************************************************************/
	char get_input();

	/*********************************************************************
	** Function: play_game()
	** Description: actually runs the game until game is over
	** Parameters: none
	** Pre-Conditions: Game is created
	** Post-Conditions: Player won or lost
	*********************************************************************/
	void play_game();

	/*********************************************************************
	** Function:percept_display()
	** Description:checks if player is adjacent to an Event room and prints
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: if player is next to event room, percept is called
	*********************************************************************/
	void percept_display();
	
	/*********************************************************************
	** Function: encounter_display()
	** Description: handles encounter for all events
	** Parameters:none
	** Pre-Conditions: user is in a room
	** Post-Conditions: event encounter is called if room contains event
	*********************************************************************/
	void encounter_display();

	/*********************************************************************
	** Function: get_width()
	** Description: ask user for width and error check
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: width is from 4-50
	*********************************************************************/
	int get_width();

	/*********************************************************************
	** Function: get_length()
	** Description: ask user for length and error check
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: length is from 4-50
	*********************************************************************/
	int get_length();

	/*********************************************************************
	** Function: get_debug
	** Description: ask user for debug mode and error check
	** Parameters: none
	** Pre-Conditions: none
	** Post-Conditions: debug is either 0 or 1
	*********************************************************************/
	bool get_debug();

};
#endif