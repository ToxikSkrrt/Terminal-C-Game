#include <stdlib.h>

#include "inventory.h"
#include "monster.h"

char *monster_getName(monster_t monster) {
  return monster->name;
}

int monster_getLevel(monster_t monster) {
  return monster->level;
}

int monster_getHp(monster_t monster) {
  return monster->hp;
}

int monster_getAtk(monster_t monster) {
  return monster->atk;
}

int monster_getArmor(monster_t monster) {
  return monster->armor;
}

inventory_t monster_getInventory(monster_t monster) {
  return monster->inventory;
}

void monster_setName(monster_t monster, char *name) {
  monster->name = name;
}

void monster_setLevel(monster_t monster, int level) {
  monster->level = level;
}

void monster_setHp(monster_t monster, int hp) {
  monster->hp = hp;
}

void monster_setAtk(monster_t monster, int atk) {
  monster->atk = atk;
}

void monster_setArmor(monster_t monster, int armor) {
  monster->armor = armor;
}

void monster_setInventory(monster_t monster, inventory_t inventory) {
  monster->inventory = inventory;
}

monster_t monster_create(char *name, int level, int hp, int atk, int armor) {
  item_t EMPTY_ITEM = item_create("No item", 0, 0, 0);

  monster_t monster = (monster_t)malloc(sizeof(struct monster_s));

  monster_setName(monster, name);
  monster_setLevel(monster, level);
  monster_setHp(monster, hp);
  monster_setAtk(monster, atk);
  monster_setArmor(monster, armor);

  inventory_t inventory = inventory_create(item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM));

  monster_setInventory(monster, inventory);

  return monster;
}

void monster_delete(monster_t monster) {
  free(monster->name);
  inventory_delete(monster->inventory);

  free(monster);
}