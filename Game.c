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
  printf("%s\n", "Hello");
  Map *test = generateMap("Test Map", 10, 10);
  printMap(test);

  while (TRUE)
  {
    // printMap(test);
    char direction = askForMove();
    move(test, direction);
    //system("cls");
  }

  free(test);

  return 0;
}
