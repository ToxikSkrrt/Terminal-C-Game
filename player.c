#include "player.h"
#include "inventory.h"
#include "item.h"

char *player_getName(player_t player) {
  return player.name;
}

int player_getLevel(player_t player) {
  return player.level;
}

int player_getHp(player_t player) {
  return player.hp;
}

int player_getAtk(player_t player) {
  return player.atk;
}

int player_getArmor(player_t player) {
  return player.armor;
}

inventory_t player_getInventory(player_t player) {
  return player.inventory;
}

void player_setName(player_t player, char *name) {
  player.name = name;
}

void player_setLevel(player_t player, int level) {
  player.level = level;
}

void player_setHp(player_t player, int hp) {
  player.hp = hp;
}

void player_setAtk(player_t player, int atk) {
  player.atk = atk;
}

void player_setArmor(player_t player, int armor) {
  player.armor = armor;
}

void player_setInventory(player_t player, inventory_t inventory) {
  player.inventory = inventory;
}

player_t player_create(char *name, int level, int hp, int atk, int armor) {
  player_t player = {name, level, hp, atk, armor};
  inventory_t inventory = inventory_create(EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM, EMPTY_ITEM);

  player_setInventory(player, inventory);

  return player;
}