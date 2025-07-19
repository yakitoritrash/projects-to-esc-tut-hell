#include <stdio.h>


char board[] =
  {' ', ' ', ' ',
   ' ', ' ', ' ',
   ' ', ' ', ' ',};
int size = sizeof(board) / sizeof(board[0]);

void tictactoe() {

}
void printboard() {
  for (int i = 0; i < 3; i++) {
    printf("%c | ", board[i]);
  }
  printf("\n");
  for (int i = 3; i < 6; i++) {
    printf("%c | ", board[i]);
  }
  printf("\n");
  for (int i = 6; i < 9; i++) {
    printf("%c | ", board[i]);
  }
  printf("\n");
}

int main() {
  printboard();
}
