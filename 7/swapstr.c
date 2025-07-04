#include <stdio.h>
#include <stdlib.h>

void str_swap(char **a, char **b) {
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  char *a = malloc(2 * sizeof(char));
  char *b = malloc(2 * sizeof(char));

  if (a == NULL || b == NULL) {
    printf("Memory allocation failed.");
    return 1;
  }
  scanf("%c", a);
  scanf("%c", b);
  printf("%c %c\n", *a, *b);
  str_swap(&a, &b);
  printf("%c %c", *a, *b);
  free(a);
  free(b);
  return 0;
}
