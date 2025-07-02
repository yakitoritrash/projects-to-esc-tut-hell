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
  node_t *tmp = head;
  for (int i = 0; i < position; i++) {
    if (tmp->next != NULL && tmp != NULL) {
      tmp = tmp->next;
    }
  }
  if (tmp->next == NULL || tmp == NULL) {
    printf("out of bounds.\n");
    return head;
  }
  new_node->next = tmp->next;
  tmp->next = new_node;

  if (tmp->next != NULL) {
    tmp->next->prev = new_node;
  }
  if (tmp != NULL) {
    new_node->prev = tmp;
  }
  return head;
}

node_t *delete_at(node_t *head, int position) {
  if (head == NULL) {
    printf("nothing to delete\n");
    return NULL;
  }
  if (position == 0) {
    node_t *to_delete = head;
    head = head->next;
    free(to_delete);
  }
  node_t *tmp = head;
  for (int i = 0; i <= position; i++) {
    if (tmp != NULL && tmp->next != NULL) {
      tmp = tmp->next;
    }
  }
  if (tmp == NULL || tmp->next == NULL) {
    printf("Out of bound.\n");
    return head;
  }
  node_t *to_delete = tmp;
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  free(to_delete);

  return head;
}

node_t *delete_value(node_t *head, int val) {
  if (head->value == val) {
    node_t *to_delete = head;
    head = head->next;
    free (to_delete);
  }
  node_t *tmp = head;
  while (tmp->next->value == val && tmp->next != NULL) {
    tmp = tmp->next;
  }
  node_t *to_delete = tmp->next;
  tmp->next = to_delete->next;
  if (to_delete->next != NULL) {
    to_delete->next->prev = tmp;
  }
  free (to_delete);
  return head;
}

int main() {
  node_t *head = NULL;
  head = create_node(5);
  head = prepend(head, 10);
  head = prepend(head, 15);
  head = append(head, 2);
  head = insert_at(head, 2, 20);
  head = delete_at(head, 2);

  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d <-> ", tmp->value);
    tmp = tmp->next;
  }
  printf("NULL");
}
