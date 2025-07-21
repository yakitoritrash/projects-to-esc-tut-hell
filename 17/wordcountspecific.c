#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  int ch;
  while ((ch = fgetc(fptr)) != EOF) {
    putchar(ch);
  }
  return 0;
}
