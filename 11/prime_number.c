#include <stdio.h>
#include <stdbool.h>

bool primechecker() {
  int num;
  scanf("%d", &num);
  for (int i = 2; i <= num*num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int res = (int)primechecker();
  printf("%d", res);
}
