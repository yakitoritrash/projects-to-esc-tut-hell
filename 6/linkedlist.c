#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
  int value;
  struct node_t *next;
  struct node_t *prev;
} node_t;

node_t *create_node (int val) {
  node_t *new_node = malloc(sizeof(node_t));
  if (!new_node) {
    printf("Memory allocation failed.");
    return NULL;
  }
  new_node->value = val;
  new_node->next= NULL;
  new_node->prev = NULL;
  return new_node;
}

node_t *prepend(node_t *head, int val) {
  node_t *new_node = create_node(val);
  if (new_node == NULL) {
    return head;
  }
  new_node->next = head;
  if (new_node->next) {
    new_node->next->prev = new_node;
  }
  head = new_node;
  return head;
}

int main() {
  node_t *head = NULL;
  create_node(5);
  prepend(head, 10);
  prepend(head, 15);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d -> ", tmp->value);
    tmp = tmp->next;
  }
}
