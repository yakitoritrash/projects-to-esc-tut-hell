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

task_t *insert_task(char *task, 
