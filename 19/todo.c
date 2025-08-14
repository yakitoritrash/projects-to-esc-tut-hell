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

}
