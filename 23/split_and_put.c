#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_split(char* string) {
  char* res = malloc(strlen(string) + 1);
  strcpy(res, string);
  return res;
}

int main() {
  char* new_string = string_split("hello");
  for (int i = 0; i < strlen(new_string); i++) {
    printf("%c ", new_string[i]); 
  }
}
