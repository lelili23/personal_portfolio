CC=g++ -std=c++11 -g
EXE_FILE=asm4

# Complete the makefile
# Your code here: 
$(EXE_FILE): main.o bats.o event.o game.o gold.o room.o stalactites.o wumpus.o
	$(CC) main.o bats.o event.o game.o gold.o room.o stalactites.o wumpus.o -o $(EXE_FILE)

main.o: main.cpp 
	$(CC) -c main.cpp

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

stalactities.o: stalactities.cpp stalactities.h
	$(CC) -c stalactities.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

clean:
	rm -f *.o $(EXE_FILE)