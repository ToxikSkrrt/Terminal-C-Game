#include <stdio.h>
#include <stdlib.h>

#include "inventory.h"
#include "item.h"
#include "player.h"
#include "tools.h"

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
  char str[10];
  sleepPrint("***************************\n", 10);
  sleepPrint("Infos:\n", TEXTSPEED);
  sleepPrint("Name: ", TEXTSPEED);
  sleepPrint(player_getName(player), TEXTSPEED);
  sleepPrint("\n", TEXTSPEED);
  sleepPrint("Level: ", TEXTSPEED);
  sprintf(str, "%d", player_getLevel(player));
  sleepPrint(str, TEXTSPEED);
  sleepPrint("\n", TEXTSPEED);
  sleepPrint("HP: ", TEXTSPEED);
  sprintf(str, "%d", player_getHp(player));
  sleepPrint(str, TEXTSPEED);
  sleepPrint("\n", TEXTSPEED);
  sleepPrint("Attack: ", TEXTSPEED);
  sprintf(str, "%d", player_getAtk(player));
  sleepPrint(str, TEXTSPEED);
  sleepPrint("\n", TEXTSPEED);
  sleepPrint("Armor: ", TEXTSPEED);
  sprintf(str, "%d", player_getArmor(player));
  sleepPrint(str, TEXTSPEED);
  sleepPrint("\n", TEXTSPEED);
  sleepPrint("***************************\n", 10);
  sleepPrint("Inventory:\n", TEXTSPEED);
  inventory_showInfo(player_getInventory(player));
  sleepPrint("***************************\n", 10);
}