#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void todo() {
  char choice;
  scanf("%c", &choice);
  char **strings = NULL;
  int size = 5;
  strings = (char**)malloc(sizeof(char*));
  if (choice == 'a') {

  }
}
int main() {
  printf("Type 'a' to add a task.\n");
  printf("Type 'd' to delete a task.\n");
  printf("Type 'v' to view the task list.\n");
  todo();
}
