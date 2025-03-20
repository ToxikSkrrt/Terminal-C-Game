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
  hideCursor();
  sleep(1);

  sleepPrint("START GAME", TEXTSPEED);
  sleep_ms(900);
  sleepPrint("...", 1000);

  sleep(1);

  char scanInput[9999];
  do {
    consoleClear();
    sleepPrint("Enter your name (max 10 characters): ", TEXTSPEED);
    showCursor();
    fgets(scanInput, sizeof(scanInput), stdin);
    scanInput[strcspn(scanInput, "\n")] = '\0';
    hideCursor();

    if (strlen(scanInput) > 10) {
      consoleClear();
      sleepPrint("Name too long !", TEXTSPEED);
      sleep(1);
      fflush(stdin);
    }
  } while (strlen(scanInput) > 10);

  consoleClear();

  player_t player = player_create(scanInput, 1, 10, 2, 0);
  sleepPrint("NEW PLAYER CREATED !", TEXTSPEED);
  sleep(1);
  consoleClear();
  player_showInfo(player, false);

  sleep(1);
  consoleClear();

  // monster_t monster = monster_create("Garrosh", 1, 5, 1, 1);
  // sleepPrint("NEW MONSTER CREATED !\n", TEXTSPEED);
  // sleep(1);
  // monster_showInfo(monster);

  // sleep(1);
  // consoleClear();

  while (true) {
    printf("[A] Attack\n");
    printf("[E] Use an item\n");
    printf("[R] Retreat\n");
    printf("[Q] Quit the game");

    fflush(stdin);

    char ch = getch();

    consoleClear();

    if (ch == 'q') {
      sleepPrint("Thanks for playing !", TEXTSPEED);
      sleep(2);
      consoleClear();
      break;
    } else if (ch == 'a')
      printf("=> Attack !\n");
    else if (ch == 'e')
      printf("=> Item used !\n");
    else if (ch == 'r')
      printf("=> Retreat !\n");
    else
      printf("=> Not implemented.\n");

    sleep(1);

    consoleClear();
  }
}