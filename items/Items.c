#include "stdio.h"

#include "..\maps\Maps.h"
#include "Items.h"
#include "..\input\InputController.h"

int gold_amount = 0;
int inventoryOpen = 0;

void checkItemPickup(Map *map, char direction)
{
  char up = map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]];
  char down = map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]];
  char left = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1];
  char right = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1];

  switch (direction)
  {
    case MOVE_UP:
      if(up == GOLD)
        gold_amount++;
      break;


    case MOVE_LEFT:
      if(left == GOLD)
        gold_amount++;
      break;


    case MOVE_RIGHT:
      if(right == GOLD)
        gold_amount++;
      break;


    case MOVE_DOWN:
      if(down == GOLD)
        gold_amount++;
      break;
  }
}

void showInventory()
{
  if(inventoryOpen == 0)
    inventoryOpen = 1;
  else
    inventoryOpen = 0;
  system("cls");
  printf("%25s\n", "Inventory - Press 1 to quit");
  printf("Gold amount: %d\n", gold_amount);
}
