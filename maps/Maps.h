#ifndef MAPS_H_
#define MAPS_H_

// TODO: Dynamic map generater based on sizes given.
typedef struct {
  char* name;
  int x, y;

  //Change 10, 10 to the max map size I decide on later. This will always
  char map[10][10];

} Map;

void generateMap(Map *map);
void printMap(Map *map);

#endif
