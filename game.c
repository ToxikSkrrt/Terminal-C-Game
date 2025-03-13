#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include "monster.h"
#include "player.h"
#include "tools.h"

void player_attack(player_t player, monster_t monster) {
  monster_setHp(monster, monster_getHp(monster) - player_getAtk(player) - monster_getArmor(monster));
}

void monster_attack(monster_t monster, player_t player) {
  player_setHp(player, player_getHp(player) - monster_getAtk(monster) - player_getArmor(player));
}

void runGame() {
  consoleClear();
  sleep(1);

  sleepPrint("START GAME", 100);
  sleep_ms(900);
  sleepPrint("...", 1000);

  sleep(2);
  consoleClear();

  player_t player = player_create("Toxik", 1, 10, 2, 0);
  sleepPrint("NEW PLAYER CREATED !", 100);
  sleep(1);
  printf("\n");
  player_showInfo(player);

  sleep(2);
  consoleClear();

  monster_t monster = monster_create("Garrosh", 1, 5, 1, 1);
  sleepPrint("NEW MONSTER CREATED !", 100);
  sleep(1);
  printf("\n");
  monster_showInfo(monster);

  sleep(2);
  consoleClear();

  while (true) {
    printf("[1] Attack\n");
    printf("[2] Use an item\n");
    printf("[3] Retreat\n");
    printf("[Q] Quit the game\n");

    char ch;
    ch = getch();

    consoleClear();

    if (ch == 'q') {
      sleepPrint("Thanks for playing !", 100);
      sleep(2);
      consoleClear();
      break;
    } else if (ch == '1')
      printf("=> Attack !\n");
    else if (ch == '2')
      printf("=> Item used !\n");
    else if (ch == '3')
      printf("=> Retreat !\n");
    else
      printf("=> Not implemented.\n");

    sleep(1);

    consoleClear();
  }
}