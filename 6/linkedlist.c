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
