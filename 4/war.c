#include <stdio.h>


typedef struct cards_t {
  int value;
  char* suit;
} cards_t;

typedef struct deck_t {
  int cards_t[];

} deck_t;
