#include "player.h"

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

player_t player_create(char *name, int level, int hp, int atk, int armor) {
  player_t player = {name, level, hp, atk, armor};

  return player;
}