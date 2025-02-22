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

#endif