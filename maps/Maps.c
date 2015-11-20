#include "Maps.h"
#include "stdlib.h"
#include "stdio.h"

void printMap(Map *map)
{
  int i;
  int j;
  printf("%s\n", map->name);
  for (i = 0; i < map->x + 1; i++)
  {
    for (j = 0; j < map->y + 1; j++)
      printf("%c ", map->map[i][j]);

    printf("\n");
  }
}

void generateMap(Map *map)
{
  int i, j;

  for (i = 0; i < map->x; i++)
  {
    for (j = 0; j < map->y; j++)
    {
      if(i = 0)
        map->map[i][j] = i;
      else if (j = 0)
        map->map[i][j] = i;
      else
        map->map[i][j] = '-';
    }
  }
}
