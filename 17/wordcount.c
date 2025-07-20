#include <stdio.h>

int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  int ch;
  while ((ch = fgetc(fptr)) != EOF) {
    putchar(ch);
  }
  fclose(fptr);
  return 0;
}
