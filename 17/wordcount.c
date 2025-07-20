#include <stdio.h>

int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  int ch;
  int count = 0;
  char* word;
  scanf("%s", word);
  while ((ch = fgetc(fptr)) != EOF) {
    if (ch == ' ') {
      count++;
    }
  }
  printf("%d words", count);
  fclose(fptr);
  return 0;
}
