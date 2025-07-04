#include <stdio.h>
#include <stdlib.h>

void str_swap(char **a, char **b) {
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  char *a = malloc(100 * sizeof(char));
  char *b = malloc(100 * sizeof(char));

  if (a == NULL || b == NULL) {
    printf("Memory allocation failed.");
    return 1;
  }
  scanf("%99s\n", a);
  scanf("%99s", b);
  printf("%s %s\n", a, b);
  str_swap(&a, &b);
  printf("%s %s", a, b);
  free(a);
  free(b);
  return 0;
}
