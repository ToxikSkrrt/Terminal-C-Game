#include "monster.h"
#include "player.h"

void player_attack(player_t player, monster_t monster) {
  monster.hp -= player.atk - monster.armor;
}

void monster_attack(monster_t monster, player_t player) {
  player.hp = monster.atk - player.armor;
}