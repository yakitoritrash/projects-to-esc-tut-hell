#include <stdio.h>

#define MAX_URL_LENGTH 2048
#define SHORT_URL_LENGTH 6

void hashFunction(char *longURL, char *shortURL) {
  unsigned long hash = 5381;
  int c;

  while ((c = *longURL++)) {
    hash = ((hash << 5) + hash) + c;
  }

  snprintf(shortURL, SHORT_URL_LENGTH, "%lx", hash % 1000000);
}

void storeURL(char *longURL, char *shortURL) {

}
