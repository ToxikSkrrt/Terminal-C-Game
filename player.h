#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "inventory.h"

struct player_s {
  char *name;
  int level;
  int hp;
  int atk;
  int armor;
  inventory_t inventory;
};

typedef struct player_s *player_t;

char *player_getName(player_t player);
int player_getLevel(player_t player);
int player_getHp(player_t player);
int player_getAtk(player_t player);
int player_getArmor(player_t player);
inventory_t player_getInventory(player_t player);

void player_setName(player_t player, char *name);
void player_setLevel(player_t player, int level);
void player_setHp(player_t player, int hp);
void player_setAtk(player_t player, int atk);
void player_setArmor(player_t player, int armor);
void player_setInventory(player_t player, inventory_t inventory);

player_t player_create(char *name, int level, int hp, int atk, int armor);
void player_delete(player_t player);
void player_showInfo(player_t player);

#endif