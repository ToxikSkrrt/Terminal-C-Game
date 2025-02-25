#ifndef __GAME_H__
#define __GAME_H__

#include "monster.h"
#include "player.h"

void player_attack(player_t player, monster_t monster);
void monster_attack(monster_t monster, player_t player);

void runGame();

#endif