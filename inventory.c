#include "inventory.h"
#include "item.h"

item_t inventory_getMainHand(inventory_t inventory) {
  return inventory.mainHand;
}

item_t inventory_getOffHand(inventory_t inventory) {
  return inventory.offHand;
}

item_t inventory_getHead(inventory_t inventory) {
  return inventory.head;
}

item_t inventory_getShoulders(inventory_t inventory) {
  return inventory.shoulders;
}

item_t inventory_getTorso(inventory_t inventory) {
  return inventory.torso;
}

item_t inventory_getHands(inventory_t inventory) {
  return inventory.hands;
}

item_t inventory_getLegs(inventory_t inventory) {
  return inventory.legs;
}

item_t inventory_getFeet(inventory_t inventory) {
  return inventory.feet;
}

void inventory_setMainHand(inventory_t inventory, item_t mainHand) {
  inventory.mainHand = mainHand;
}

void inventory_setOffHand(inventory_t inventory, item_t offHand) {
  inventory.offHand = offHand;
}

void inventory_setHead(inventory_t inventory, item_t head) {
  inventory.head = head;
}

void inventory_setShoulders(inventory_t inventory, item_t shoulders) {
  inventory.shoulders = shoulders;
}

void inventory_setTorso(inventory_t inventory, item_t torso) {
  inventory.torso = torso;
}

void inventory_setHands(inventory_t inventory, item_t hands) {
  inventory.hands = hands;
}

void inventory_setLegs(inventory_t inventory, item_t legs) {
  inventory.legs = legs;
}

void inventory_setFeet(inventory_t inventory, item_t feet) {
  inventory.feet = feet;
}

inventory_t inventory_create(item_t mainHand, item_t offHand, item_t head, item_t shoulders, item_t torso, item_t hands, item_t legs, item_t feet) {
  inventory_t inventory = {mainHand, offHand, head, shoulders, torso, hands, legs, feet};

  return inventory;
}