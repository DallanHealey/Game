#ifndef MAPS_H_
#define MAPS_H_

// TODO: Dynamic map generater based on sizes given.
// TODO: Rewrite Map generator
// TODO: Possibly change char numbers to char*



typedef struct {
  char* name;
  int x, y;
  int currentPlayerLocation[2];

  //Change 10, 10 to the max map size I decide on later. Will need to make map generator more dynamic
  //Game will crash if map size is bigger than [x - 1][y - 1]
  char map[11][11];

} Map;

Map* generateMap(char* name, int sizeX, int sizeY);
void printMap(Map *map);

#endif
