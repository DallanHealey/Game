# Makefile generated by Makefile Generator at Thu Nov 26 01:29:54 CST 2015 #
all : Game.o input\InputController.o maps\Maps.o 
	 gcc Game.o input\InputController.o maps\Maps.o 
Game.o : Game.c maps\Maps.h input\InputController.h 
	 gcc -c Game.c 
InputController.o : input\InputController.c input\..\maps\Maps.h input\InputController.h 
	 gcc -c input\InputController.c 
Maps.o : maps\Maps.c maps\Maps.h 
	 gcc -c maps\Maps.c 
