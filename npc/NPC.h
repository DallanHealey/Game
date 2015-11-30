#ifndef NPC_H
#define NPC_H

// TODO: Make when spacebar is pressed checks for NPC around player then interacts with it. Proabaly easiest way to do it

#define NPC_IDENTIFIER 63
#define SPACEBAR 32

int dialogueOpen;

typedef struct
{
  char* name;
  char* dialogue[4];
  int location[2];
} NPC;

void checkNPC(Map *map);
void talkNPC(Map *map, NPC *npc);
NPC* createNPC(Map *map, char* name, char* dialogue[4], int location[2]);

#endif
