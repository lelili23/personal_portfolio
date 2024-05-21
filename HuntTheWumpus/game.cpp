/******************************************************
** Program: game.cpp
** Author: Lilian Le
** Description: Simulates a Hunt the Wumpus game where 
player guides an adventurer to kill Wumpus, find gold,
and escape to win while navigating many dangers along
the way.
******************************************************/
#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"

#include <iostream>

using namespace std;

Game::Game(){
	//sets variables to beginning game status
	this->wumpus_alive = true;
	this->player_alive = true;
	this->have_gold = false;
	this->confused_moves = 0;
}

Game::~Game(){}

void Game::set_up(int l, int w){
	this->rows = w; 	//set rows and columns size
	this->columns = l;
	
	this->pos_x = rand() % w; //set player starting position
    this->pos_y = rand() % l;

	this->inital_x = pos_x; //save inital position for escape rope
	this->inital_y = pos_y;

	this->num_arrows = 3; 	//start with 3 arrows
	
	// Create the game board: 2D vector of Room objects
	this->grid.resize(rows);
	for (int i = 0; i < rows; i++) {
		grid.at(i).resize(columns);
	}

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	this->insert_event(new Bats);
	this->insert_event(new Bats);
	this->insert_event(new Stalactites);
	this->insert_event(new Stalactites);
	this->insert_event(new Wumpus);
	this->insert_event(new Gold);
}

void Game::insert_event(Event* e) {
	int rows_idx;
	int columns_idx;
	do {
		// Choose a random row
		rows_idx = rand() % grid.size();
		// Choose a random column
		columns_idx = rand() % (grid.at(0).size());
	//reprompt if room has event or player is in it
	} while(grid.at(rows_idx).at(columns_idx).get_event() != nullptr || (rows_idx == pos_x && columns_idx == pos_y));

	//save wumpus position	
	if(e->get_event_type() == 'W') {
		wumpus_x = rows_idx;
		wumpus_y = columns_idx;
	}

	// Place the event
	grid.at(rows_idx).at(columns_idx).set_event(e);
}

void Game::display_game(){
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl; //display remaining arrows
	
	string line = "";
	for (int i = 0; i < this->columns; ++i) //display row border
		line += "+---";
	for (int i = 0; i < this->rows; ++i) {
		cout << line << "+" << endl;
		for (int j = 0; j < this->columns; ++j){
			cout << "|";
			if (pos_x == i && pos_y == j) { //if room contains position of player print *
                cout << "*";
			} else {
                cout << " ";
			}
			Game::print_debug(i,j); //print debug characters
			if (j == this->columns - 1) {
                cout << "|";
            }
		}
       	cout << endl;
	}
	cout << line << "+" << endl;
}

void Game::print_debug(int i, int j) {
	//if room is empty and doesn't contain player print empty
	if (grid.at(i).at(j).get_event() == nullptr && !(inital_x == i && inital_y == j)) {
                cout << "  ";
	//if room contains escape rope and debug is on, print E
	} else if((inital_x == i && inital_y == j) && debug_view ==1) {
				cout << "E "; 
	//if room contains an event and debug is on, print event
	} else if (debug_view == 1) { 
		Event* roomEvent = grid.at(i).at(j).get_event();
		cout << roomEvent->get_event_type() << " ";
	} else {
		cout << "  ";
	}
}

bool Game::check_win() const{
	//if wumpus is dead, game won
	if(wumpus_alive==false) {
		cout << "Congrats! You have killed Wumpus. Great Job!" << endl;
		return true;
	}
	//if player is dead, game lost
	if(player_alive == false) {
		return true;
	}
	//if gold is picked up, but not at inital position, game continues
	if(have_gold == true && !(pos_x == inital_x && pos_y == inital_y)) {
		cout << "You have picked up the gold, but are not at starting position!" << endl;
		return false;
	}
	//if gold is picked up and at initial position, game won
	if(have_gold == true && (pos_x == inital_x && pos_y == inital_y)) {
		cout << "Congrats! You have picked up the gold and returned to the escape rope!" << endl;
		return true;
	}
	return false;
}

void Game::move_up() {
	//if regular move, move up a row
	if(confused_moves == 0) {
		if(pos_x-1 >=0) {
			pos_x--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	} else { //if a confused move, do opposite direction
		if(pos_x+1 < rows) {
			pos_x++;
			confused_moves--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	}
	return;
}

void Game::move_down() {
	//if regular move, move down a row	
	if(confused_moves == 0) {
		if(pos_x+1 < rows) {
			pos_x++;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	} else { //if a confused move, do opposite direction
		if(pos_x-1 >=0) {
			pos_x--;
			confused_moves--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	}
	return;
}

void Game::move_left() {
	//if regular move to left
	if(confused_moves == 0) {
		if(pos_y-1 >=0) {
			pos_y--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	} else { //if a confused move, do opposite direction
		if(pos_y+1 < columns) {
			pos_y++;
			confused_moves--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	}
	return;

}

void Game::move_right() {
	//if regular move, move to right
	if(confused_moves == 0) {
		if(pos_y+1 < columns) {
			pos_y++;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	} else { //if a confused move, do opposite direction
		if(pos_y-1 >=0) {
			pos_y--;
			confused_moves--;
		} else {
			cout << "Sorry out of bounds. Enter a different direction." << endl;
		}
	}
	return;
}

char Game::get_dir(){
	char dir;

	//get direction until it is ASWD
	do {
		cout << endl << "Fire an arrow...." << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;

		cout << "Enter direction: ";
		cin >> dir;
		cin.ignore(256, '\n');

		// Convert the input to uppercase for 
		dir = toupper(dir);

		if (dir != 'W' && dir != 'A' && dir != 'S' && dir != 'D') {
			cout << "Invalid input. Please enter W, A, S, or D." << endl;
		}
    } while (dir != 'W' && dir != 'A' && dir != 'S' && dir != 'D');

	return dir;
}

void Game::wumpus_move(){
	// generate 75% chance
	int chance = rand() % 4;
	
	// if 75% chance Wumpus moves
	if (chance != 0) {
		int temp_row, temp_col;
		do { //find new coordinates that are empty
			temp_row = rand() % grid.size();
			temp_col = rand() % (grid.at(0).size());
		} while(grid.at(temp_row).at(temp_col).get_event() != nullptr || (temp_row == pos_x && temp_col == pos_y));
		
		//clear room Wumpus is in
		grid.at(wumpus_x).at(wumpus_y).set_event(nullptr);

		//assign Wumpus new coordinates
		wumpus_x = temp_row;
		wumpus_y = temp_col;

		//assign Wumpus to new room
		grid.at(temp_row).at(temp_col).set_event(new Wumpus);

		cout << endl << "Arrow was missed! Wumpus woke up and has moved." << endl;
	} else {
		cout <<  endl << "Arrow was missed! Wumpus woke up, but did not move." << endl;
	}
	

}

void Game::fire_arrow(){
	char dir = get_dir();
	num_arrows--;
	if(dir == 'W') { //fires it up
		for(int i = 1; i < 4; i++) { //checks 3 rooms in direction if contains Wumpus
			if(pos_x-i == wumpus_x && pos_y == wumpus_y) {
				wumpus_alive = false;
			}
		}
	}
	if(dir== 'A') { //fires it left
		for(int i = 1; i < 4; i++) {
			if(pos_x == wumpus_x && pos_y-i == wumpus_y) {
				wumpus_alive = false;

			}
		}
	}
	if(dir=='D') { //fires it right
		for(int i = 1; i < 4; i++) {
			if(pos_x == wumpus_x && pos_y+i == wumpus_y) {
				wumpus_alive = false;

			}
		}
	}
	if(dir=='S') { //fires it down
		for(int i = 1; i < 4; i++) {
			if(pos_x+i == wumpus_x && pos_y == wumpus_y) {
				wumpus_alive = false;
			}
		}
	}
	if (wumpus_alive == true) { //if shot missed, move wumpus
		wumpus_move();
	}
}

void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'F'){ 
		if (num_arrows > 0) { //cehcks if user has arrows remaining
		Game::fire_arrow();
		return; 
		} else {
			cout << "You have no more arrows." << endl;
			return;
		}
	}
	switch(c){  //moves based on user's direction
		case 'W':
			Game::move_up();
			break;
		case 'A':
			Game::move_left();
			break;
		case 'S':
			Game::move_down();
			break;
		case 'D':
			Game::move_right();
			break;
	}
}

char Game::get_input(){
	char c;

	do {
		cout << endl << endl << "Player move..." << endl << endl;
		cout << "W-up" << endl;
		cout << "A-left" << endl;
		cout << "S-down" << endl;
		cout << "D-right" << endl;
		cout << "F-fire an arrow" << endl;

		cout << "Enter input: ";
		cin >> c;
		cin.ignore(256, '\n');

		// Convert the input to uppercase
		c = toupper(c);

		if (c != 'W' && c != 'A' && c != 'S' && c != 'D' && c != 'F') {
			cout << "Invalid input. Please enter W, A, S, D, or F." << endl;
		}
	} while (c != 'W' && c != 'A' && c != 'S' && c != 'D' && c != 'F');

	return c;
}

void Game::percept_display() {
	//checks room around position
	for (int i = pos_x - 1; i <= pos_x + 1; i++) {
        for (int j = pos_y - 1; j <= pos_y + 1; j++) {
            // check if the position is within the grid bounds
            if (i >= 0 && i < rows && j >= 0 && j < columns) {
                // check if the current position is directly next to and not diagonal 
                int x_temp = i - pos_x;
                int y_temp = j - pos_y;
                if ((x_temp == 0 && (y_temp == 1 || y_temp == -1)) || (y_temp == 0 && (x_temp == 1 || x_temp == -1))) {
                    if (grid.at(i).at(j).get_event() != nullptr) {
                        grid.at(i).at(j).get_event()->percept(); //call percept for event
                    }
                }
            }
        }
    }
}

void Game::encounter_display() {
	// if player is in a room that contains an event
	if(grid.at(pos_x).at(pos_y).get_event() != nullptr) {
		char event = grid.at(pos_x).at(pos_y).get_event()->get_event_type();
		if (event == 'S') { //if stalactites, call encounter and set player to dead if it fell
			if(grid.at(pos_x).at(pos_y).get_event()->encounter() == false) {
				player_alive = false;
			}
		} else if(event == 'G') { //if gold, set gold to picked up and clear room
			if (grid.at(pos_x).at(pos_y).get_event()->encounter()) {
				have_gold = true;
				grid.at(pos_x).at(pos_y).set_event(nullptr);
			}
		} else if(event == 'W') {// if wumpus, set player to dead
			if(grid.at(pos_x).at(pos_y).get_event()->encounter() == false) {
				player_alive = false;
			}
		} else if(event == 'B') {//if bats, set confused moves to 5
			if (grid.at(pos_x).at(pos_y).get_event()->encounter()) {
				confused_moves = 5;
			}
		}
		return;
	}
}

void Game::play_game(){
	// ask for width, length, and debug mode
	int w = Game::get_width();
	int l = Game::get_length();
	this-> debug_view = get_debug();
	
	Game::set_up(l, w); //set up grid and events

	char input, arrow_input;
	
	while (Game::check_win() == false){
		Game::display_game(); //display grid

		Game::percept_display(); //check for percepts
		
		input = Game::get_input(); //get user next move

		Game::move(input); //move user or shoot arrow

		Game::encounter_display(); //check for encounters
	}
	return;

}

int Game::get_width() {
	//get a valid width from 4-50
	int wid;
	do {
        cout << "Enter width (rows) of the cave (4-50): ";
        cin >> wid;

        if (wid < 4 || wid > 50) {
            cout << "Invalid input. Width must be between 4 and 50." << endl;
        }
    } while (wid < 4 || wid > 50);
	return wid;
}

int Game::get_length() {
	//get a valid length from 4-50
	int len;
	do {
        cout << "Enter length (columns) of the cave (4-50): ";
        cin >> len;

        if (len < 4 || len > 50) {
            cout << "Invalid input. Length must be between 4 and 50." << endl;
        }
    } while (len < 4 || len > 50);
	return len;
}

bool Game::get_debug() {
	//get a valid debug mode 0 or 1
	string debug;
	do {
        cout << "Enter 0 for normal mode or 1 for debug mode: ";
        cin >> debug;

        if (debug != "0" && debug != "1") {
            cout << "Invalid input. Debug mode must be 0 or 1." <<endl;
        }
    } while (debug != "0" && debug != "1");

	bool debugBool = (debug == "1");

	return debugBool;
}
