#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#include "game.h"
#include "monster.h"
#include "player.h"
#include "tools.h"

void player_save(player_t player) {
  FILE *file = fopen("data/player_data.txt", "w");
  if (!file)
    return;

  fprintf(file, "player_name: %s\n", player_getName(player));
  fprintf(file, "player_level: %d\n", player_getLevel(player));
  fprintf(file, "player_hp: %d\n", player_getHp(player));
  fprintf(file, "player_atk: %d\n", player_getAtk(player));
  fprintf(file, "player_armor: %d\n", player_getArmor(player));

  fclose(file);
}

player_t player_load() {
  FILE *file = fopen("data/player_data.txt", "r");
  if (!file) {
    perror("Failed to open file");
    return NULL;
  }

  player_t player = player_create("NULL", 0, 0, 0, 0);
  char line[128];

  while (fgets(line, sizeof(line), file)) {
    char key[64], value[64];
    if (sscanf(line, "%[^:]: %[^\n]", key, value) == 2) {
      if (strcmp(key, "player_name") == 0) {
        player_setName(player, value);
      } else if (strcmp(key, "player_level") == 0) {
        player_setLevel(player, atoi(value));
      } else if (strcmp(key, "player_hp") == 0) {
        player_setHp(player, atoi(value));
      } else if (strcmp(key, "player_atk") == 0) {
        player_setAtk(player, atoi(value));
      } else if (strcmp(key, "player_armor") == 0) {
        player_setArmor(player, atoi(value));
      }
    }
  }

  fclose(file);

  return player;
}

void player_attack(player_t player, monster_t monster) {
  monster_setHp(monster, monster_getHp(monster) - player_getAtk(player) - monster_getArmor(monster));
}

void monster_attack(monster_t monster, player_t player) {
  player_setHp(player, player_getHp(player) - monster_getAtk(monster) - player_getArmor(player));
}

void launchGame() {
  hideCursor();
  sleep(1);

  int value = 0;

  while (true) {
    if (value == 0)
      printf("=> New game\n");
    else
      printf("   New game\n");
    if (value == 1)
      printf("=> Continue game\n");
    else
      printf("   Continue game\n");
    if (value == 2)
      printf("=> Settings\n");
    else
      printf("   Settings\n");
    if (value == 3)
      printf("=> Quit game\n");
    else
      printf("   Quit game\n");

    fflush(stdin);

    char ch = getch();
    if (ch == '\033') {
      getch();
      switch (getch()) {
      case 'A':
        if (value > 0)
          value--;
        break;
      case 'B':
        if (value < 3)
          value++;
        break;
      }
    } else if (ch == '\n') {
      consoleClear();

      if (value == 0) {
        runGame(true);
        break;
      } else if (value == 1) {
        runGame(false);
        break;
      } else if (value == 2) {
        continue;
      } else {
        break;
      }
    }

    consoleClear();
  }
}

void runGame(bool reset) {
  sleepPrint("START GAME", TEXTSPEED);
  sleep_ms(900);
  sleepPrint("...", 1000);

  sleep(1);

  if (reset) {
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

    player_save(player);

    sleepPrint("NEW PLAYER CREATED !", TEXTSPEED);
    sleep(1);
    consoleClear();
    player_showInfo(player, false);

    sleep(1);
  } else {
    player_t player = player_load();

    consoleClear();
    player_showInfo(player, false);

    sleep(1);
  }

  consoleClear();

  while (true) {
    printf("[A] Attack\n");
    printf("[E] Use an item\n");
    printf("[R] Retreat\n");
    printf("[Q] Quit the game");

    fflush(stdin);

    char ch = getch();

    consoleClear();

    if (ch == 'q') {
      sleepPrint("Exiting...", TEXTSPEED);
      sleep(2);
      consoleClear();
      return;
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