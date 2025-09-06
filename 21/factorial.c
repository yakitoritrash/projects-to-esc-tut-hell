#include <stdio.h>
#include <string.h>

void multiplyString(char num[], int factor) {
  int len = strlen(num);
  int carry = 0;
  printf("%d %s %d %d\n", len, num, factor, carry);
  for (int i = len - 1; i >= 0; i--) {
    int digit = num[i] - '0';
    int product = digit * factor + carry;
    num[i] = (product % 10) + '0';
    carry = product / 10;
  }
  while (carry) {
    for (int i = strlen(num); i >= 0; i--) {
      num[i + 1] = num[i];
    }
    num[0] = (carry % 10) + '0';
    carry /= 10;
  }
}

void factorialString(int N) {
  char fact[1000];
  strcpy(fact, "1");
  printf("%s\n", fact);
  for (int i = 2; i <= N; i++) {
    multiplyString(fact, i);
  }
  printf("Factorial of %d is %s", N, fact); 
}

int main() {
  int N = 21;
  factorialString(N);
  return 0;
}
