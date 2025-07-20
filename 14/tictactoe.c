#include <stdio.h>
#include <stdbool.h>

void tictactoe(char board[], int size, int player) {
  if (player == 1) {
    int player1_choice;
    scanf("%d", &player1_choice);
    if (board[player1_choice - 1] == ' ') {
      board[player1_choice - 1] = 'X';
    } else {
      printf("Invalid move. Try again, only one more chance though\n");
      scanf("%d", &player1_choice);
      if (board[player1_choice - 1] == ' ') {
        board[player1_choice - 1] = 'X';
      } 
    }
  }
  if (player == 2) {
    int player2_choice;
    scanf("%d", &player2_choice);
    if (board[player2_choice - 1] == ' ') {
      board[player2_choice - 1] = 'O';
    } else {
      printf("Invalid move. Try again, only one more chance though\n");
      scanf("%d", &player2_choice);
      if (board[player2_choice - 1] == ' ') {
        board[player2_choice - 1] = 'O';
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

bool winnerfunc(char board[]) {
  if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2]
  || board[0] != ' ' && board[0] == board[3] && board[3] == board[6]
  || board[0] != ' ' && board[0] == board[4] && board[4] == board[8]) {
    printf("%c wins.\n", board[0]);
    return true;
  }
  if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]) {
    printf("%c wins.\n", board[1]);
    return true;
  }
  if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]
  || board[2] != ' ' && board[2] == board[4] && board[4] == board[6]) {
    printf("%c wins.\n", board[2]);
    return true;
  }
  if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]) {
    printf("%c wins.\n", board[3]);
    return true;
  }
  if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]) {
    printf("%c wins.\n", board[6]);
    return true;
  }
  return false;
}

int main() {
char board[] =
  {' ', ' ', ' ',
   ' ', ' ', ' ',
   ' ', ' ', ' ',};
int size = sizeof(board) / sizeof(board[0]);
  for (int i = 0; i <= size - 1; i++) {
    while (!winnerfunc(board)) {
      printboard(board);
      tictactoe(board, size, 1);
    }
  }
}
