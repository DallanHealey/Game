#include "malloc.h"
#include "stdio.h"

#include "../maps/Maps.h"
#include "NPC.h"
#include "../input/InputController.h"


int dialogueOpen = 0;

void checkNPC(Map *map, char direction)
{
  char up = map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]];
  char down = map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]];
  char left = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1];
  char right = map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1];

  switch (direction)
  {
    case MOVE_UP:
      if(up == NPC_IDENTIFIER)
//        talkNPC();
      break;

    case MOVE_LEFT:
      if(left == NPC_IDENTIFIER)
//        talkNPC();
      break;

    case MOVE_RIGHT:
      if(right == NPC_IDENTIFIER)

      break;

    case MOVE_DOWN:
      if(down == NPC_IDENTIFIER)

      break;
  }
}

void talkNPC(Map *map, NPC *npc)
{
  if(dialogueOpen == 0)
    dialogueOpen = 1;
  else
    dialogueOpen = 0;
  system("cls");
  printf("%25s\n", "Talking - Press 5 to quit");

  int i;
  for(i = 0; i < 4; i++)
    printf("%d: %s\n", i + 1, npc->dialogue[i]);

  int option;
  scanf("%d\n", &option);
  if(option == 5)
  {
    system("cls");
    printMap(map);
  }
  else
    printf("%s\n", npc->dialogue[option - 1]);
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
