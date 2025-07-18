#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/select.h>

int kbhit() {
  struct timeval tv = { 0L, 0L };
  fd_set fds;
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  return select(1, &fds, NULL, NULL, &tv);
}
void stopwatch() {
  int i = 0;
  char choice;
  printf("p to pause the stopwatch.\n c to continue. \n r to reset the stopwatch");
  while (1) {
    printf("\rTime elapsed: %d seconds", i);
    fflush(stdout);
    sleep(1);
    i++;
    if (kbhit()) {
      choice = getchar();
      if (choice == 'p') {
        printf("\nStopwatch paused. Press 'c' to continue. 'r' to reset or 'q' to quit.\n");
        while (1) {
          choice = getchar();
          if (choice == 'c') {
            break;
          } else if (choice == 'r') {
            i = 0;
            break;
          } else if (choice == 'q') {
            return;
          }
        }
      }
    }
  }
}

int main() {
  printf("type 'start' to start\n");
  printf("type 'pause' to pause\n");
  printf("type 'stop' to stop\n");
  stopwatch();
}
