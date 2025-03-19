#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "monster.h"
#include "player.h"

int main(int argc, char **argv) {
  if (argc == 1) {
    system("gnome-terminal -- bash -c './main new_terminal'");
  } else {
    runGame();

    return EXIT_SUCCESS;
  }
}