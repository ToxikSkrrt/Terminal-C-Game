#include <stdlib.h>

#include "inventory.h"
#include "item.h"
#include "player.h"

char *player_getName(player_t player) {
  return player->name;
}

int player_getLevel(player_t player) {
  return player->level;
}

int player_getHp(player_t player) {
  return player->hp;
}

int player_getAtk(player_t player) {
  return player->atk;
}

int player_getArmor(player_t player) {
  return player->armor;
}

inventory_t player_getInventory(player_t player) {
  return player->inventory;
}

void player_setName(player_t player, char *name) {
  player->name = name;
}

void player_setLevel(player_t player, int level) {
  player->level = level;
}

void player_setHp(player_t player, int hp) {
  player->hp = hp;
}

void player_setAtk(player_t player, int atk) {
  player->atk = atk;
}

void player_setArmor(player_t player, int armor) {
  player->armor = armor;
}

void player_setInventory(player_t player, inventory_t inventory) {
  player->inventory = inventory;
}

player_t player_create(char *name, int level, int hp, int atk, int armor) {
  player_t player = (player_t)malloc(sizeof(sizeof(struct player_s)));

  player_setName(player, name);
  player_setLevel(player, level);
  player_setHp(player, hp);
  player_setAtk(player, atk);
  player_setArmor(player, armor);

  item_t EMPTY_ITEM = item_create("No item", 0, 0, 0);
  inventory_t inventory = inventory_create(item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM), item_copy(EMPTY_ITEM));

  player_setInventory(player, inventory);

  return player;
}

void player_delete(player_t player) {
  free(player->name);
  inventory_delete(player->inventory);

  free(player);
}

void player_showInfo(player_t player) {
  printf("- - - - - - -");
  printf("Name: %s\n", player_getName(player));
  printf("Level  %d\n", player_getLevel(player));
  printf("HP: %d\n", player_getHp(player));
  printf("Attack: %d\n", player_getAtk(player));
  printf("Armor: %d\n\n", player_getArmor(player));
  printf("- - - - - - -");
  prinf("Inventory:");
  inventory_showInfo(player_getInventory(player));
  printf("- - - - - - -");
}