#include <stdio.h>
#include <stdlib.h>

#include "item.h"

char *item_getName(item_t item) {
  return item->name;
}

int item_getHp(item_t item) {
  return item->hp;
}

int item_getAtk(item_t item) {
  return item->atk;
}

int item_getArmor(item_t item) {
  return item->armor;
}

void item_setName(item_t item, char *name) {
  item->name = name;
}

void item_setHp(item_t item, int hp) {
  item->hp = hp;
}

void item_setAtk(item_t item, int atk) {
  item->atk = atk;
}

void item_setArmor(item_t item, int armor) {
  item->armor = armor;
}

item_t item_create(char *name, int hp, int atk, int armor) {
  item_t item = (item_t)malloc(sizeof(struct item_s));

  item_setName(item, name);
  item_setHp(item, hp);
  item_setAtk(item, atk);
  item_setArmor(item, armor);

  return item;
}

item_t item_copy(item_t item) {
  item_t item_cpy = item_create(item_getName(item), item_getHp(item), item_getAtk(item), item_getArmor(item));

  return item_cpy;
}

void item_delete(item_t item) {
  free(item->name);
  free(item);
}

void item_showInfo(item_t item) {
  printf("Name: %s\n", item_getName(item));
  printf("HP: %d\n", item_getHp(item));
  printf("Attack: %d\n", item_getAtk(item));
  printf("Armor: %d\n", item_getArmor(item));
}