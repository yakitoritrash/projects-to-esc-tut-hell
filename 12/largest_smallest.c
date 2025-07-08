#include <stdio.h>
#include <stdlib.h>

int* largest_smallest(int arr[], int size) {
  int* res = malloc(2 * sizeof(int));
  int max = 0; 
  int min = 123*123; 
  for (int i = 0; i < size; i++) {
    if (arr[i] >= max) {
      max = arr[i];
    }
    if (arr[i] <= min) {
      min = arr[i];
    }
  }
  res[0] = max;
  res[1] = min;
  return res;
}

int main() {
  int arr[] = {34, 12, 56, 223, 76, 43, 90};
  int size = sizeof(arr) / sizeof(arr[0]);
  int* res = largest_smallest(arr, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  for (int i = 0; i < 2; i++) {
    printf("%d ", res[i]);
  }
}
