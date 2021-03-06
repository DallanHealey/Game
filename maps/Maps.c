#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"

#include "Maps.h"
#include "../npc/NPC.h"
#include "../items/Items.h"

void printMap(Map *map)
{
	system("cls");

	int i;
	int j;
	printf("Currently on %s\n", map->name);
	for (i = 0; i <= map->x; i++)
	{
		for (j = 0; j <= map->y; j++)
			printf("%c ", map->map[i][j]);

		printf("\n");
	}
}

// This method is a little long. It generates up to a 10x10 map. The switch methods are a little meh.
Map* generateMap(char* name, int sizeX, int sizeY)
{
	Map *map = malloc(sizeof(Map));
	map->name = name;
	map->x = sizeX;
	map->y = sizeY;

	char* dialogueNPC[4] = { "Test", "Help", "Please", "Easy" };
	int location[2] = { 5, 5 };
	NPC *npc = createNPC(map, "Erika", dialogueNPC, location);
	map->npcs[0] = npc;

	//Sets player location
	map->currentPlayerLocation[0] = rand() % sizeX;
	map->currentPlayerLocation[1] = rand() % sizeY;

	int i, j;
	for (i = 0; i <= map->x; i++)
	{
		for (j = 0; j <= map->y; j++)
		{
			map->map[i][j] = '-';
		}
	}

	map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = PLAYER;
	map->map[2][2] = GOLD;
	map->map[5][4] = GOLD;

	map->map[5][5] = NPC_IDENTIFIER;

	return map;
}
