#include <stdio.h>
#include <stdlib.h>

int main() {
  int upper_bound = 100;
  int lower_bound= 1;
  int value = rand() % (upper_bound - lower_bound + 1) + lower_bound;
  printf(" %d", value);
  int j = rand();
  printf("%d", j);
  return 0;
}
