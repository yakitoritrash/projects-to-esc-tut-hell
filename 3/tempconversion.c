#include <stdio.h>

int main() {
  int celsius;
  printf("Temperature in celsius: ");
  scanf("%d", &celsius);
  int fahrenheit;
  fahrenheit = (celsius * 9/5) + 32;
  printf("Temperature in fahrenheit: %d", fahrenheit);
  return 0;
}
