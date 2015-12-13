#ifndef MAPS_H_
#define MAPS_H_

// TODO: Make the map generator generate NPCs and items.

#define PLAYER 42

typedef struct
{
	char* name;
	int x, y;
	int currentPlayerLocation[2];

	//Right now max of 5 npcs per map
	struct NPC *npcs[5];
	//Game will crash if map size is bigger than [x - 1][y - 1]
	char map[101][101];

} Map;

Map* generateMap(char* name, int sizeX, int sizeY);
void printMap(Map *map);

#endif
