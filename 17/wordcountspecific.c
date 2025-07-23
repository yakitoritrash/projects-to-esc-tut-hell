#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_BUFFER_SIZE 100

int main() {
  FILE *fptr;
  fptr = fopen("test.txt", "r");
  if (fptr == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  int ch;
  char sword[WORD_BUFFER_SIZE];
  scanf("%s", sword);
  char word[WORD_BUFFER_SIZE];
  int count = 0;
  while (fscanf(fptr, "%s", word) != EOF) {
    if (strcasecmp(word, sword) == 0) {
      count++;
    }
  }
  printf("%s: %d", sword, count);
  return 0;
}
