#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  int ch;
  char *word = malloc(10 * sizeof(char));
  scanf("%s", word);
  printf("%s", word);
  while ((ch = fgetc(fptr)) != EOF) {
    putchar(ch);
  }
  fclose(fptr);
  return 0;
}
