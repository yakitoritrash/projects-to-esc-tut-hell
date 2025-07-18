#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int upper_bound = 100;
  int value = rand() % (upper_bound + 1);
  int guess;
  while (guess != value) {
    printf("Guess the number: \n");
    scanf("%d", &guess);
    if (guess > value) {
      printf("%d is too high\n", guess);
    } else if (guess < value) {
      printf("%d is too low\n", guess);
    } else if (guess == value) {
      printf("That's right %d is the number.\n", value);
    }
  }
  return 0;
}
