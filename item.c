#include "item.h"

char *item_getName(item_t item) {
  return item.name;
}

int item_getHp(item_t item) {
  return item.hp;
}

int item_getAtk(item_t item) {
  return item.atk;
}

int item_getArmor(item_t item) {
  return item.armor;
}

void item_setName(item_t item, char *name) {
  item.name = name;
}

void item_setHp(item_t item, int hp) {
  item.hp = hp;
}

void item_setAtk(item_t item, int atk) {
  item.atk = atk;
}

void item_setArmor(item_t item, int armor) {
  item.armor = armor;
}

item_t item_create(char *name, int hp, int atk, int armor) {
  item_t item = {name, hp, atk, armor};

  return item;
}
