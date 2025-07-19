#include <stdio.h>


char board[] =
  {' ', ' ', ' ',
   ' ', ' ', ' ',
   ' ', ' ', ' ',};
int size = sizeof(board) / sizeof(board[0]);

void tictactoe() {

}
void printboard() {
  for (int i = 0; i < size; i++) {
    printf("%c | ", board[i]);
  }
}

int main() {
  printboard();
}
