#include "stdio.h"
#include "malloc.h"
#include "ctype.h"

#include "maps/Maps.h"

#define TRUE 1
#define FALSE 0

int moveDataX, moveDataY;

void move(Map *map, int x, int y)
{
  map->map[x + 1][y + 1] = '*';
  map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
  map->currentPlayerLocation[0] = x + 1;
  map->currentPlayerLocation[1] = y + 1;
}

void askForMove(void)
{
  char temp;
  printf("%s\n", "Please enter a place to move to (e.g. 0,0): ");
  scanf("%d%c%d", &moveDataX, &temp, &moveDataY);
}

int main(int argc, char const *argv[])
{
  system("cls");

  Map *s = malloc(sizeof(Map));

  s->name = "Test Map";

  s->x = 10;
  s->y = 10;

  generateMap(s);
  //printf("%s\n", "Map generated");

  while (TRUE)
  {
    printMap(s);
    askForMove();
    move(s, moveDataX, moveDataY);
    system("cls");
  }

  free(s);

  return 0;
}
