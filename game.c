#include "monster.h"
#include "player.h"

player_t player_create(char *name, int level, int hp, int atk, int armor) {
  player_t player = {name, level, hp, atk, armor};

  return player;
}

void player_attack(player_t player, monster_t monster) {
  monster.hp -= player.atk - monster.armor;
}

monster_t monster_create(char *name, int level, int hp, int atk, int armor) {
  monster_t monster = {name, level, hp, atk, armor};

  return monster;
}

void monster_attack(monster_t monster, player_t player) {
  player.hp = monster.atk - player.armor;
}