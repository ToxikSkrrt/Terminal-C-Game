#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "item.h"

typedef struct {
  item_t mainHand;
  item_t offHand;
  item_t head;
  item_t shoulders;
  item_t torso;
  item_t hands;
  item_t legs;
  item_t feet;
} inventory_t;

item_t inventory_getMainHand(inventory_t inventory);
item_t inventory_getOffHand(inventory_t inventory);
item_t inventory_getHead(inventory_t inventory);
item_t inventory_getShoulders(inventory_t inventory);
item_t inventory_getTorso(inventory_t inventory);
item_t inventory_getHands(inventory_t inventory);
item_t inventory_getLegs(inventory_t inventory);
item_t inventory_getFeet(inventory_t inventory);

void inventory_setMainHand(inventory_t inventory, item_t mainHand);
void inventory_setOffHand(inventory_t inventory, item_t offHand);
void inventory_setHead(inventory_t inventory, item_t head);
void inventory_setShoulders(inventory_t inventory, item_t shoulders);
void inventory_setTorso(inventory_t inventory, item_t torso);
void inventory_setHands(inventory_t inventory, item_t hands);
void inventory_setLegs(inventory_t inventory, item_t legs);
void inventory_setFeet(inventory_t inventory, item_t feet);

inventory_t inventory_create(item_t mainHand, item_t offHand, item_t head, item_t shoulders, item_t torso, item_t hands, item_t legs, item_t feet);

#endif