#ifndef NPC_H
#define NPC_H

// TODO: Make when spacebar is pressed checks for NPC around player then interacts with it. Proabaly easiest way to do it

#define NPC_IDENTIFIER 63

int dialogueOpen;
int movementLocation[2];

struct NPC
{
  char* name;
  char* dialogue[4];
  int location[2];
};

// This needs to be here because I declare the NPC struct in the Map struct.
// If this is not here it causes an error of undefined type because of alias refrencing or something
typedef struct NPC NPC;

int *checkNPC(Map *map);
void talkNPC(Map *map, NPC *npc);
NPC* createNPC(Map *map, char* name, char* dialogue[4], int location[2]);

#endif
