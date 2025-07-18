#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int upper_bound = 1;
  int value = rand() % (upper_bound + 1);
  int guess;
  while (guess != value) {
    printf("Guess the number: \n");
    scanf("%d\n", &guess);
    if (guess > value) {
      printf("too high\n");
    } else if (guess < value) {
      printf("too low\n");
    } else {
      printf("That's right %d is the number.\n", value);
    }
  }
  return 0;
}
