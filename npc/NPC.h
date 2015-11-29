#ifndef NPC_H
#define NPC_H

#define NPC_IDENTIFIER 63

int dialogueOpen;

typedef struct
{
  char* name;
  char* dialogue[4];
  int location[2];
} NPC;

void checkNPC(Map *map, char direction);
void talkNPC(Map *map, NPC *npc);
NPC* createNPC(Map *map, char* name, char* dialogue[4], int location[2]);

#endif
