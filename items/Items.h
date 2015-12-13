#ifndef ITEMS_H
#define ITEMS_H

int inventoryOpen;

//Variables of current item amount
int gold_amount;

//Item definitions
#define GOLD 36

//Functions
void checkItemPickup(Map *map, char direction);
void showInventory(void);

#endif
