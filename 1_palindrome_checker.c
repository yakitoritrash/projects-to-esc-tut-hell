#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool PalCheck(char *str) {
  char *newstr = "";
  for (int i = strlen(str); i >= 0; i--) {
    newstr += str[i];
  }
  if (strcmp(str, newstr) == 0) {
    return true;
  }
  return false;
}

int main() {
  char *str = "bob";
  int result = (int)PalCheck(str);
  printf("%d", result);
}
