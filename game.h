#ifndef __GAME_H__
#define __GAME_H__

#include "monster.h"
#include "player.h"

player_t player_create(char *name, int level, int hp, int atk, int armor);
void player_attack(player_t player, monster_t monster);

monster_t monster_create(char *name, int level, int hp, int atk, int armor);
void monster_attack(monster_t monster, player_t player);

#endif