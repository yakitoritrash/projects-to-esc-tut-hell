#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  char* close = malloc(sizeof(char));
  while (strcmp(close, "c") == 0) {
    scanf("%s", close);
    char* input = malloc(sizeof(char));
    scanf("%s", input);
    printf("%s", input);
    if (strcmp(input, "s") == 0) {
      
    }
  }
}

int main() {
  printf("type 'start' to start\n");
  printf("type 'pause' to pause\n");
  printf("type 'stop' to stop\n");
  stopwatch();
}
