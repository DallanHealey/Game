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
	Map *test = generateMap("Test Map", 20, 20);
	printMap(test);

	while (TRUE)
	{
		char direction = askForMove();
		move(test, direction);
	}

	free(test);

	return 0;
}
