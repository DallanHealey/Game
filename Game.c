#include "stdio.h"
#include "maps/Maps.h"
#include "malloc.h"

#define TRUE 1
#define FALSE 0

int currentPlayerLocation[] = {2, 2};

int moveData[] = {0, 0};
int moveDataX = 0, moveDataY;



void move(Map *map, int x, int y)
{
  map->map[x + 1][y + 1] = '*';
  map->map[currentPlayerLocation[0]][currentPlayerLocation[1]] = '-';
  currentPlayerLocation[0] = x + 1;
  currentPlayerLocation[1] = y + 1;
}

void askForMove(void)
{
  char temp;
  printf("%s\n", "Please enter a place to move to (e.g. 0,0): ");
  scanf("%d%c%d", &moveDataX, &temp, &moveDataY);
  printf("%s\n", "Done");
}

int main(int argc, char const *argv[])
{
  printf("%s\n", "Hello");

  Map *s = malloc(sizeof(Map));

  s->name = "Map1";
  s->x = 5;
  s->y = 5;

  generateMap(s);
  printf("%s\n", "Map generated");


  while (TRUE)
  {
    printMap(s);
    askForMove();
    move(s, moveDataX, moveDataY);
  }

  free(s->map);
  free(s);

  return 0;
}
