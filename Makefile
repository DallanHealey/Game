# Makefile generated by Makefile Generator at Sun Dec 13 11:11:20 CST 2015 #
all : Game.o input\InputController.o items\Items.o maps\Maps.o npc\NPC.o 
	 gcc Game.o input\InputController.o items\Items.o maps\Maps.o npc\NPC.o 
Game.o : Game.c maps\Maps.h input\InputController.h 
	 gcc -c Game.c 
InputController.o : input\InputController.c input\..\maps\Maps.h input\..\npc\NPC.h input\..\items\Items.h input\InputController.h 
	 gcc -c input\InputController.c 
Items.o : items\Items.c items\Items.h 
	 gcc -c items\Items.c 
Maps.o : maps\Maps.c maps\Maps.h maps\..\npc\NPC.h maps\..\items\Items.h 
	 gcc -c maps\Maps.c 
NPC.o : npc\NPC.c npc\..\maps\Maps.h npc\NPC.h npc\dialogue\Dialogue.h npc\..\input\InputController.h 
	 gcc -c npc\NPC.c 
