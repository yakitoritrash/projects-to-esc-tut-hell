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
  }
}

int main() {
  printf("type 'start' to start\n");
  printf("type 'pause' to pause\n");
  printf("type 'stop' to stop\n");
  stopwatch();
}
