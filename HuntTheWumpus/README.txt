# Hunt The Wumpus

Recreation of the Hunt the Wumpus using polpymorphism.
Hunt the Wumpus takes place inside a cave with a monster named the Wumpus.
The player's goal to is to navigate through the cave to either kill the 
Wumpus, or find its hidden gold and escape alive. The cave is a grid of rooms
with 4 tunnels. The starting location is the location of the "escape rope" that
the player must use to escape. Each room can contain one of: 2 kinds of hazards,
the Wumpus, and the gold treasure. The player wins if they pick up the gold and 
make it back to escape rope alive or they kill the Wumpus by shooting an arrow.

# Usage
To use, run the makefile, and then it will prompt for the grid size and if the
program will run in debug mode or regular. Debug mode will show the map marked with
all the events. 