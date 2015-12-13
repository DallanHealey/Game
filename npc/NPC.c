#include "malloc.h"
#include "stdio.h"

#include "../maps/Maps.h"
#include "NPC.h"
#include "dialogue/Dialogue.h"
#include "../input/InputController.h"

int dialogueOpen = 0;

int *checkNPC(Map *map)
{
	//printf("%s\n", "Checking for NPC");

	char up = map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]];
	char down = map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]];
	char left = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1];
	char right = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1];

	if (up == NPC_IDENTIFIER)
	{
		static int movementLocation[2];
		movementLocation[0] = map->currentPlayerLocation[0] - 1;
		movementLocation[1] = map->currentPlayerLocation[1];
		return movementLocation;
	}
	else if (down == NPC_IDENTIFIER)
	{
		static int movementLocation[2];
		movementLocation[0] = map->currentPlayerLocation[0] + 1;
		movementLocation[1] = map->currentPlayerLocation[1];
		return movementLocation;
	}
	else if (left == NPC_IDENTIFIER)
	{
		static int movementLocation[2];
		movementLocation[0] = map->currentPlayerLocation[0];
		movementLocation[1] = map->currentPlayerLocation[1] - 1;
		return movementLocation;
	}
	else if (right == NPC_IDENTIFIER)
	{
		static int movementLocation[2];
		movementLocation[0] = map->currentPlayerLocation[0];
		movementLocation[1] = map->currentPlayerLocation[1] + 1;
		return movementLocation;
	}
	else return 0;
}

void talkNPC(Map *map, NPC *npc)
{
	if (dialogueOpen == 0)
		dialogueOpen = 1;
	else dialogueOpen = 0;
	system("cls");
	printf("Talking to %s - Press 5 to quit\n", npc->name);

	int i;
	for (i = 0; i < 4; i++)
		printf("%d: %s\n", i + 1, npc->dialogue[i]);
	int option = 0;
	do
	{
		char optionChar = getch();
		if (optionChar == SPACEBAR)
			continue;

		option = optionChar - '0';
		if (option <= 4)
			printf("%s\n", npc->dialogue[option - 1]);
	} while (option != 5);

	printMap(map);
}

NPC* createNPC(Map *map, char* name, char* dialogueValues[4], int location[2])
{
	int i;

	NPC *npc = malloc(sizeof(NPC));
	npc->name = name;
	npc->location[0] = location[0];
	npc->location[1] = location[1];

	for (i = 0; i < 4; i++)
		npc->dialogue[i] = dialogueValues[i];

	return npc;
}
