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
  if (head != NULL) {
    head->prev = new_node;
  }
  head = new_node;
  return new_node;
}

node_t *append(node_t *head, int val) {
  node_t *new_node = create_node(val);
  if (new_node == NULL) {
    return head;
  }
  if (head == NULL) {
    return new_node;
  }
  node_t *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = new_node;
  if (tmp != NULL) {
    new_node->prev = tmp;
  }
  return head;
}

node_t *insert_at(node_t *head, int position, int val) {
  node_t *new_node = create_node(val);
  if (new_node == NULL) {
    return head;
  }
  if (head == NULL) {
    return NULL;
  }

  return head;
}

int main() {
  node_t *head = NULL;
  head = create_node(5);
  head = prepend(head, 10);
  head = prepend(head, 15);
  head = append(head, 2);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->value);
    tmp = tmp->next;
  }
  printf("NULL");
}
