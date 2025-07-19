#include <stdio.h>


void tictactoe(char board[], int size) {
  for (int i = 0; i < size; i++) {
    while (board[i] == ' ') {
      int player1_choice;
      scanf("%d", &player1_choice);
      if (board[player1_choice - 1] == ' ') {
        board[player1_choice - 1] = 'X';
      } else {
        printf("Invalid move.\n");
      }
      int player2_choice;
      scanf("%d", &player2_choice);
      if (board[player2_choice - 1] == ' ') {
        board[player2_choice - 1] = 'O';
      } else {
        printf("Invalid move.\n");
      }
    }
  }
}
void printboard(char board[]) {
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
char board[] =
  {' ', ' ', ' ',
   ' ', ' ', ' ',
   ' ', ' ', ' ',};
int size = sizeof(board) / sizeof(board[0]);
  printboard(board);
  tictactoe(board, size);
  printboard(board);
}
