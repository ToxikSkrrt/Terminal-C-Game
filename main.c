#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "monster.h"
#include "player.h"

int main(int argc, char **argv) {
  player_t player = player_create(argv[1], 1, 10, 2, 0);
  printf("NEW PLAYER CREATED !\n");
  printf("Name: %s\n", player_getName(player));
  printf("Level  %d\n", player_getLevel(player));
  printf("HP: %d\n", player_getHp(player));
  printf("Attack: %d\n", player_getAtk(player));
  printf("Armor: %d\n\n", player_getArmor(player));

  printf("------------------------\n\n");

  monster_t monster = monster_create(argv[2], 1, 5, 1, 1);
  printf("NEW MONSTER CREATED !\n");
  printf("Name: %s\n", monster_getName(monster));
  printf("Level  %d\n", monster_getLevel(monster));
  printf("HP: %d\n", monster_getHp(monster));
  printf("Attack: %d\n", monster_getAtk(monster));
  printf("Armor: %d\n", monster_getArmor(monster));

  return EXIT_SUCCESS;
}