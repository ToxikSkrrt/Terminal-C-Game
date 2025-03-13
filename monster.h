#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "inventory.h"

struct monster_s {
  char *name;
  int level;
  int hp;
  int atk;
  int armor;
  inventory_t inventory;
};

typedef struct monster_s *monster_t;

char *monster_getName(monster_t monster);
int monster_getLevel(monster_t monster);
int monster_getHp(monster_t monster);
int monster_getAtk(monster_t monster);
int monster_getArmor(monster_t monster);
inventory_t monster_getInventory(monster_t monster);

void monster_setName(monster_t monster, char *name);
void monster_setLevel(monster_t monster, int level);
void monster_setHp(monster_t monster, int hp);
void monster_setAtk(monster_t monster, int atk);
void monster_setArmor(monster_t monster, int armor);
void monster_setInventory(monster_t monster, inventory_t inventory);

monster_t monster_create(char *name, int level, int hp, int atk, int armor);
void monster_delete(monster_t monster);
void monster_showInfo(monster_t monster);

#endif