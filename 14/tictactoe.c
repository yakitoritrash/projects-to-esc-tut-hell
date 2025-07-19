#include <stdio.h>


char board[] =
  {' ', ' ', ' ',
   ' ', ' ', ' ',
   ' ', ' ', ' ',};
int size = sizeof(board) / sizeof(board[0]);

void tictactoe() {
  int player1_choice;
  scanf("%d", &player1_choice);
  if (board[player1_choice - 1] == ' ') {
    board[player1_choice - 1] = 'X';
  }
}
void printboard() {
  for (int i = 0; i <= 2; i++) {
    if (i == 2) {
      printf("%c", board[2]);
    } else {
      printf("%c | ", board[i]);
    }
  }
  printf("\n---------\n");
  for (int i = 3; i <= 5; i++) {
    if (i == 5) {
      printf("%c", board[5]);
    } else {
      printf("%c | ", board[i]);
    }
  }
  printf("\n---------\n");
  for (int i = 6; i <= 8; i++) {
    if (i == 8) {
      printf("%c", board[8]);
    } else {
      printf("%c | ", board[i]);
    }
  }
  printf("\n");
}

int main() {
  printboard();
  tictactoe();
  printboard();
}
