#ifndef NPC_H
#define NPC_H

// TODO: Make when spacebar is pressed checks for NPC around player then interacts with it. Proabaly easiest way to do it

#define NPC_IDENTIFIER 63

int dialogueOpen;
int movementLocation[2];

typedef struct
{
  char* name;
  char* dialogue[4];
  int location[2];
} NPC;

NPC *testMapNPC[1];

int *checkNPC(Map *map);
void talkNPC(Map *map, NPC *npc);
NPC* createNPC(Map *map, char* name, char* dialogue[4], int location[2]);

#endif
