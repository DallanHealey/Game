#include "../maps/Maps.h"
#include "InputController.h"
#include "stdio.h"

void move(Map *map, char direction)
{
  /*
  map->map[x + 1][y + 1] = '*';
  map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';
  map->currentPlayerLocation[0] = x + 1;
  map->currentPlayerLocation[1] = y + 1;
  */

  map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1]] = '-';

//Checks movement direction then applies the movement
  //Moves up
  if (direction == 'H')
  {
    map->map[map->currentPlayerLocation[0] - 1][map->currentPlayerLocation[1]] = '*';
    map->currentPlayerLocation[0] -= 1;
  }
  //Moves left
  else if (direction == 'K')
  {
    map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] - 1] = '*';
    map->currentPlayerLocation[1] -= 1;
  }
  //Moves right
  else if (direction == 'M')
  {
    map->map[map->currentPlayerLocation[0]][map->currentPlayerLocation[1] + 1] = '*';
    map->currentPlayerLocation[1] += 1;
  }
  //Moves down
  else if (direction == 'P')
  {
      map->map[map->currentPlayerLocation[0] + 1][map->currentPlayerLocation[1]] = '*';
      map->currentPlayerLocation[0] += 1;
  }

}

char askForMove(void)
{
  char temp;
  printf("%s\n", "Use arrow keys to move");

//Test
  //Need to catch \0 because the up key is \0 + H
  char c;
  c = getch();
  if (c != '\0')
  {
    //printf("Char entered: %c\n", c);
  }
  else
  {
    char arrow = getch();
    switch (arrow)
    {
      //Up
      case 'H':
      return 'H';
      break;

      //Left
      case 'K':
      return 'K';
      break;

      //Right
      case 'M':
      return 'M';
      break;

      //Down
      case 'P':
      return 'P';
      break;
    }
  }

//End test


  //scanf("%d%c%d", &moveDataX, &temp, &moveDataY);
}
