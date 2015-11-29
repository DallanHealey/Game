#ifndef MAPS_H_
#define MAPS_H_

// TODO: Dynamic map generater based on sizes given.
// TODO: Rewrite Map generator

#define PLAYER '*'

typedef struct {
  char* name;
  int x, y;
  int currentPlayerLocation[2];

  //Game will crash if map size is bigger than [x - 1][y - 1]
  char map[101][101];

} Map;

Map* generateMap(char* name, int sizeX, int sizeY);
void printMap(Map *map);

#endif
