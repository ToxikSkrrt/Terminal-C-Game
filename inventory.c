#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "item.h"
#include "tools.h"

item_t inventory_getMainHand(inventory_t inventory) {
  return inventory->mainHand;
}

item_t inventory_getOffHand(inventory_t inventory) {
  return inventory->offHand;
}

item_t inventory_getHead(inventory_t inventory) {
  return inventory->head;
}

item_t inventory_getShoulders(inventory_t inventory) {
  return inventory->shoulders;
}

item_t inventory_getTorso(inventory_t inventory) {
  return inventory->torso;
}

item_t inventory_getHands(inventory_t inventory) {
  return inventory->hands;
}

item_t inventory_getLegs(inventory_t inventory) {
  return inventory->legs;
}

item_t inventory_getFeet(inventory_t inventory) {
  return inventory->feet;
}

void inventory_setMainHand(inventory_t inventory, item_t mainHand) {
  inventory->mainHand = mainHand;
}

void inventory_setOffHand(inventory_t inventory, item_t offHand) {
  inventory->offHand = offHand;
}

void inventory_setHead(inventory_t inventory, item_t head) {
  inventory->head = head;
}

void inventory_setShoulders(inventory_t inventory, item_t shoulders) {
  inventory->shoulders = shoulders;
}

void inventory_setTorso(inventory_t inventory, item_t torso) {
  inventory->torso = torso;
}

void inventory_setHands(inventory_t inventory, item_t hands) {
  inventory->hands = hands;
}

void inventory_setLegs(inventory_t inventory, item_t legs) {
  inventory->legs = legs;
}

void inventory_setFeet(inventory_t inventory, item_t feet) {
  inventory->feet = feet;
}

inventory_t inventory_create(item_t mainHand, item_t offHand, item_t head, item_t shoulders, item_t torso, item_t hands, item_t legs, item_t feet) {
  inventory_t inventory = (inventory_t)malloc(sizeof(struct inventory_s));

  inventory_setMainHand(inventory, mainHand);
  inventory_setOffHand(inventory, offHand);
  inventory_setHead(inventory, head);
  inventory_setShoulders(inventory, shoulders);
  inventory_setTorso(inventory, torso);
  inventory_setHands(inventory, hands);
  inventory_setLegs(inventory, legs);
  inventory_setFeet(inventory, feet);

  return inventory;
}

void inventory_delete(inventory_t inventory) {
  item_delete(inventory->mainHand);
  item_delete(inventory->offHand);
  item_delete(inventory->head);
  item_delete(inventory->shoulders);
  item_delete(inventory->torso);
  item_delete(inventory->hands);
  item_delete(inventory->legs);
  item_delete(inventory->feet);

  free(inventory);
}

void inventory_showInfo(inventory_t inventory) {
  sleepPrint("Main Hand: ", 100);
  sleepPrint(item_getName(inventory_getMainHand(inventory)), 100);
  printf("\n");
  sleepPrint("Off Hand: ", 100);
  sleepPrint(item_getName(inventory_getOffHand(inventory)), 100);
  printf("\n");
  sleepPrint("Head: ", 100);
  sleepPrint(item_getName(inventory_getHead(inventory)), 100);
  printf("\n");
  sleepPrint("Shoulders: ", 100);
  sleepPrint(item_getName(inventory_getShoulders(inventory)), 100);
  printf("\n");
  sleepPrint("Torso: ", 100);
  sleepPrint(item_getName(inventory_getTorso(inventory)), 100);
  printf("\n");
  sleepPrint("Hands: ", 100);
  sleepPrint(item_getName(inventory_getHands(inventory)), 100);
  printf("\n");
  sleepPrint("Legs: ", 100);
  sleepPrint(item_getName(inventory_getLegs(inventory)), 100);
  printf("\n");
  sleepPrint("Feet: ", 100);
  sleepPrint(item_getName(inventory_getFeet(inventory)), 100);
  printf("\n");
}