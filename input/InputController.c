#include "stdio.h"
#include "stdlib.h"

#include "../maps/Maps.h"
#include "../items/Items.h"
#include "InputController.h"

void move(Map *map, char direction)
{
  checkItemPickup(map, direction);
  checkNPC(map, direction);
//Checks movement direction then applies the movement
  switch(direction)
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
      exit(1);
    break;
    case INV_KEY:
      showInventory();
    break;
    }

    if(inventoryOpen == 0)
    {
      printMap(map);
    }
}

// Asks the user to move and returns the key entered. Also handles regulaur key presses
char askForMove(void)
{
  char temp;
  printf("%s\n", "Use arrow keys to move, press 9 to quit, press 1 for inventory");

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

    default:
      return 0;
  }
}
