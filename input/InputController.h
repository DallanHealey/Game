#ifndef INPUT_H
#define INPUT_H

// TODO: Make collision detection where you cannot go out of bounds. Don't know where to put that yet
// TODO: Handle control-c


//Definitions for movement
#define MOVE_UP 72
#define MOVE_LEFT 75
#define MOVE_RIGHT 77
#define MOVE_DOWN 80

//Definitions for other key presses. Make sure to register these in the askForMove() function. Otherwise they
// 																								will not return right.
#define QUIT_KEY '9'
#define INV_KEY '1'
#define SPACEBAR 32

int *check;

void move(Map *map, char direction);
char askForMove(void);

// Frees all the malloc() objects
void freeEverything(Map *map);

#endif