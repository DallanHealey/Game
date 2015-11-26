#include "Maps.h"
#include "stdlib.h"
#include "stdio.h"
#include "malloc.h"

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

// This method is a little long. It generates up to a 10x10 map. The switch methods are a little meh.
Map* generateMap(char* name, int sizeX, int sizeY)
{
  Map *map = malloc(sizeof(Map));
  map->name = name;
  map->x = sizeX;
  map->y = sizeY;

  //Sets player location
  map->currentPlayerLocation[0] = rand() % map->x;
  map->currentPlayerLocation[1] = rand() % map->y;

  int i, j;
  for (i = 0; i <= map->x; i++)
  {
    for (j = 0; j <= map->y; j++)
    {
      switch (i)
      {
        case 0:
          switch (j)
          {
          case 0:
            map->map[i][j] = ' ';
            break;

          case 1:
            map->map[i][j] = '0';
            break;

          case 2:
            map->map[i][j] = '1';
            break;

          case 3:
            map->map[i][j] = '2';
            break;

          case 4:
            map->map[i][j] = '3';
            break;

          case 5:
            map->map[i][j] = '4';
            break;

          case 6:
            map->map[i][j] = '5';
            break;

          case 7:
            map->map[i][j] = '6';
            break;

          case 8:
            map->map[i][j] = '7';
            break;

          case 9:
            map->map[i][j] = '8';
            break;

          case 10:
            map->map[i][j] = '9';
            break;

          case 11:
            map->map[i][j] = '10';
            break;

          default:
            map->map[i][j] = '-';
          }
          break;

          case 1:
            switch (j)
            {
            case 0:
              map->map[i][j] = '0';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 2:
            switch (j)
            {
            case 0:
              map->map[i][j] = '1';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 3:
            switch (j)
            {
            case 0:
              map->map[i][j] = '2';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 4:
            switch (j)
            {
            case 0:
              map->map[i][j] = '3';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 5:
            switch (j)
            {
            case 0:
              map->map[i][j] = '4';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 6:
            switch (j)
            {
            case 0:
              map->map[i][j] = '5';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 7:
            switch (j)
            {
            case 0:
              map->map[i][j] = '6';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 8:
            switch (j)
            {
            case 0:
              map->map[i][j] = '7';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 9:
            switch (j)
            {
            case 0:
              map->map[i][j] = '8';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 10:
            switch (j)
            {
            case 0:
              map->map[i][j] = '9';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          case 11:
            switch (j)
            {
            case 0:
              map->map[i][j] = '10';
              break;

            default:
              map->map[i][j] = '-';
            }
          break;

          default:
            map->map[i][j] = '-';
        }
    }
  }
  map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '*';

  return map;
}
