#include <stdio.h>
#include <stdbool.h>

bool numberisodd(int n) {
  if (n % 2 == 0) {
    return false;
  }
  return true;
}

int main() {
  int num = 9;
  int result = (int)numberisodd(num);
  printf("%d", result);
}
