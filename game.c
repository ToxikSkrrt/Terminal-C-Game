#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "monster.h"
#include "player.h"

void player_attack(player_t player, monster_t monster) {
  monster_setHp(monster, monster_getHp(monster) - player_getAtk(player) - monster_getArmor(monster));
}

void monster_attack(monster_t monster, player_t player) {
  player_setHp(player, player_getHp(player) - monster_getAtk(monster) - player_getArmor(player));
}

void runGame() {
  // bool isRunning = true;

  player_t player = player_create("Toxik", 1, 10, 2, 0);
  printf("NEW PLAYER CREATED !\n");
  player_showInfo(player);

  printf("\n\n");

  monster_t monster = monster_create("Garrosh", 1, 5, 1, 1);
  printf("NEW MONSTER CREATED !\n");
  monster_showInfo(monster);

  // while (isRunning)
  //   ;
}