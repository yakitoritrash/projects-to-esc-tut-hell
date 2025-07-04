#include <stdio.h>

void swapInt(int *n1, int *n2) {
  int tmp = *n1;
  *n1 = *n2;
  *n2 = tmp;
}

int main() {
  int *n1;
  scanf("%d", &*n1);
  int *n2;
  scanf("%d", &*n2);
  printf("%d %d", *n1, *n2);
  swapInt(n1, n2);
  printf("%d %d", *n1, *n2);
}
