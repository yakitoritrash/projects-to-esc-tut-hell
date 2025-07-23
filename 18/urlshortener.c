#include <stdio.h>
#include <string.h>
#include <unistd.h>

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
  FILE *file = fopen("urls.txt", "a");
  if (file == NULL) {
    printf("Could not oepn file for saving URL.\n");
    return;
  }
  fprintf(file, "Long URL: %s\nShort URL: %s\n", longURL, shortURL);
  fclose(file);
}

int main() {
  char longURL[MAX_URL_LENGTH], shortURL[SHORT_URL_LENGTH];

  printf("Enter the long URL: ");
  fgets(longURL, MAX_URL_LENGTH, stdin);
  longURL[strcspn(longURL, "\n")] = 0;
  hashFunction(longURL, shortURL);
  printf("Short URL: http://short.ly/%s\n", shortURL);
  storeURL(longURL, shortURL);
  return 0;
}
