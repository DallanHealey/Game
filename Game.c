#include "stdio.h"
#include "malloc.h"
#include "ctype.h"

#include "maps/Maps.h"
#include "input/InputController.h"

#define TRUE 1
#define FALSE 0

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
    char direction = askForMove();
    move(s, direction);
    system("cls");
  }

  free(s);

  return 0;
}
