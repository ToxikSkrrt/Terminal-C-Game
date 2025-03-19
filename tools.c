
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

void consoleClear() {
  system("clear");
}

char getch() {
  struct termios oldt, newt;
  char ch;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  ch = getchar(); // Read single character without Enter

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void sleep_ms(int milliseconds) {
  struct timespec ts;
  ts.tv_sec = milliseconds / 1000;               // Convert to seconds
  ts.tv_nsec = (milliseconds % 1000) * 1000000L; // Convert to nanoseconds
  nanosleep(&ts, NULL);
}

void sleepPrint(char *input, int delay) {
  for (int i = 0; i < strlen(input); i++) {
    printf("%c", input[i]);
    fflush(stdout);
    sleep_ms(delay);
  }
}

void hideCursor() {
  printf("\e[?25l");
}

void showCursor() {
  printf("\e[?25h");
}
