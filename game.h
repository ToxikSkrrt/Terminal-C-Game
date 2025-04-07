#ifndef __GAME_H__
#define __GAME_H__

#include <stdbool.h>

#include "monster.h"
#include "player.h"

void player_save(player_t player);
player_t player_load();
void player_attack(player_t player, monster_t monster);
void monster_attack(monster_t monster, player_t player);

void launchGame();
void runGame(bool reset);

#endif