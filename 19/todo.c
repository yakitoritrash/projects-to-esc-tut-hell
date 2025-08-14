#include <stdio.h>
#include <stdlib.h>

typedef struct task_t {
  char *task; 
  struct task_t *next;
} task_t;

task_t *create_task(char *task) {
  task_t *new_task = malloc(sizeof(task_t));
  if (!new_task) {
    return NULL;
  }
  new_task->task = task;
  new_task->next = NULL;
  return new_task;
}

task_t *insert_task(char *task, task_t *head) {
  task_t *new_task = create_task(task);
  if (head == NULL) {
    return new_task;
  }
  new_task->next = head;
  head = new_task;
  return head;
}

task_t *delete_task(int pos, task_t *head) {
  task_t *tmp = head;
  for (int i = 0; i < pos; i++) {
    tmp = tmp->next;
  }
  task_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  free(to_delete);
  return head;
}

void printlist(task_t *head) {
  task_t *tmp = head;
  int i = 0;
  while (tmp != NULL) {
    printf("%d: %99s\n", i, tmp->task);
    tmp = tmp->next;
    i++;
  }
}

int main() {
  task_t *head = NULL;
  printf("Type 'A' to add a task, 'R' to delete, 'P' to show the list, 'E' to exit.\n");
  while (1) {
    char x;
    scanf("%c", &x);
    if (x == 'A') {
      char *y;
      scanf("%99s", y);
      head = insert_task(y, head);
      printf("task added.\n");
    } else if (x == 'R') {
      printlist(head);
      printf("Choose the task to delete\n");
      int y;
      scanf("%d", &y);
      head = delete_task(y, head);
      printf("task deleted.\n");
    } else if (x == 'P') {
      printlist(head);
      printf("\n");
    } else if (x == 'E') {
      break;
    } else {
      printf("choose some choice from the list.\n");
    }
  }
  return 0;
}
