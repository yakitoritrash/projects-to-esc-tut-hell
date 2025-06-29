#include <stdio.h>

int main() {
  int fahrenheit;
  printf("Temprature in fahrenheit: ");
  scanf("%d", &fahrenheit);
  int celsius;
  celsius = (fahrenheit - 32) * 5/9;
  printf("Temperature in celsius: %d", celsius);
}
