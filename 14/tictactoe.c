#include <stdio.h>

void printboard() {
  for (int i = 0; i < 3; i++) {
    printf(" | | \n");
  }
}

int main() {
  printboard();
}
