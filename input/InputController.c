#include "stdio.h"
#include "stdlib.h"

#include "../maps/Maps.h"
#include  "../npc/NPC.h"
#include "../items/Items.h"
#include "InputController.h"

void move(Map *map, char direction)
{
	//If there is a collision return. Else move.
	if (isCollision(map, direction) == 1)
		return;
	else
	{
		checkItemPickup(map, direction);

		//Checks movement direction then applies the movement. Will handle collision
		switch (direction)
		{
		case 0:
			break;

			//Movement
		case MOVE_UP:
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
			map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]] = PLAYER;
			map->currentPlayerLocation[0] -= 1;
			break;

		case MOVE_LEFT:
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1] = PLAYER;
			map->currentPlayerLocation[1] -= 1;
			break;

		case MOVE_RIGHT:
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1] = PLAYER;
			map->currentPlayerLocation[1] += 1;
			break;

		case MOVE_DOWN:
			map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
			map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]] = PLAYER;
			map->currentPlayerLocation[0] += 1;
			break;

			//Checks if other keys are pressed
		case QUIT_KEY:
			printf("Quitting...\n");
			freeEverything(map);
			exit(1);
			break;

		case INV_KEY:
			showInventory();
			break;

		case SPACEBAR:
			check = checkNPC(map);
			if (check != 0)
			{
				printf("Check was successful\n");
				int i;
				for (i = 0; i < 1; i++)
				{
					if (map->npcs[i]->location[0] == *(check + i) && map->npcs[i]->location[1] == *(check + 1 + i))
						talkNPC(map, map->npcs[i]);
					else printf("Error talking to NPC\n");
				}
			}
			break;

		default:
			printMap(map);
		}
	}
	//Checks if inventory is closed. If so, print the map
	if (inventoryOpen == 0)
	{
		printMap(map);
	}
}

//Asks the user to move and returns the key entered. Also handles regulaur key presses
char askForMove(void)
{
	char temp;
	if (inventoryOpen == 0 || dialogueOpen == 0)
		printf("%s\n", "Use arrow keys to move, press 9 to quit, press I for inventory, spacebar to talk to npcs (?)");

	char keyPressed = getch();
	switch (keyPressed)
	{
	//Movement
	//Up
	case MOVE_UP:
		return MOVE_UP;
		break;

		//Left
	case MOVE_LEFT:
		return MOVE_LEFT;
		break;

		//Right
	case MOVE_RIGHT:
		return MOVE_RIGHT;
		break;

		//Down
	case MOVE_DOWN:
		return MOVE_DOWN;
		break;
		//End Movement

	case QUIT_KEY:
		return QUIT_KEY;
		break;

	case INV_KEY:
		return INV_KEY;
		break;

	case SPACEBAR:
		return SPACEBAR;
		break;

	default:
		return 0;
	}
}

//Checks if a collision is detected. If so return 1
int isCollision(Map *map, char direction)
{

	char up = map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]];
	char down = map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]];
	char left = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1];
	char right = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1];

	switch (direction)
	{
	case 0:
		break;

		//Movement
	case MOVE_UP:
		if (up == 0)
			return 1;
		else return 0;
		break;

	case MOVE_LEFT:
		if (left == 0)
			return 1;
		else return 0;
		break;

	case MOVE_RIGHT:
		if (right <= map->x)
			return 1;
		else return 0;
		break;

	case MOVE_DOWN:
		if (down <= map->y)
			return 1;
		else return 0;
		break;

	default:
		return 0;
	}
}

// Frees all the malloc() objects
void freeEverything(Map *map)
{
	int i;
	for (i = 0; i < 1; i++)
		free(map->npcs[i]);
	free(test);
}
