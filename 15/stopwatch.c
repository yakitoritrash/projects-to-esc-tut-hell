#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stopwatch() {
  char* input = malloc(10 * sizeof(char));
  scanf("%10s", input);
  printf("%s", input);
  if (strcmp(input, "start") == 0) {

  }
}

int main() {
  printf("type 'start' to start\n");
  printf("type 'pause' to pause\n");
  printf("type 'stop' to stop\n");
  stopwatch();
}
