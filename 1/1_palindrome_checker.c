#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool PalCheck(const char *str) {
  int left = 0;
  int right = strlen(str) - 1;
  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  char *str = "bobo";
  int result = (int)PalCheck(str);
  printf("%d", result);
  return 0;
}
