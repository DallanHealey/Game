#include "stdio.h"

#include "..\maps\Maps.h"
#include "Items.h"
#include "..\input\InputController.h"

int gold_amount = 0;
int inventoryOpen = 0;

void checkItemPickup(Map *map, char direction)
{
  switch (direction)
  {
    case MOVE_UP:
      if(map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]] == GOLD)
        gold_amount = gold_amount + 1;
      break;


    case MOVE_LEFT:
      if(map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1] == GOLD)
        gold_amount = gold_amount + 1;
      break;


    case MOVE_RIGHT:
      if(map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1] == GOLD)
        gold_amount = gold_amount + 1;
      break;


    case MOVE_DOWN:
      if(map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]] == GOLD)
        gold_amount = gold_amount + 1;
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
  printf("%25s\n", "Inventory - Press I to quit");
  printf("Gold amount: %d\n", gold_amount);
}
