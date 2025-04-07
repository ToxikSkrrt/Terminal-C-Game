#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "monster.h"
#include "player.h"

const char *detect_terminal() {
  if (system("which gnome-terminal > /dev/null 2>&1") == 0) {
    return "gnome-terminal --window --full-screen --zoom=1.7 -- bash -c './main new_terminal'";
  } else if (system("which konsole > /dev/null 2>&1") == 0) {
    return "konsole --fullscreen --zoom 1.7 -e bash -c './main new_terminal'";
  } else {
    return "xterm -maximized -fa 'Monospace' -fs 14 -e './main new_terminal'";
  }
  return NULL; // Unsupported OS
}

int main(int argc, char **argv) {
  if (argc == 1) {
    const char *command = detect_terminal();
    if (command) {
      system(command);
    } else {
      printf("No supported terminal found.\n");
    }
  } else {
    launchGame();

    return EXIT_SUCCESS;
  }
}