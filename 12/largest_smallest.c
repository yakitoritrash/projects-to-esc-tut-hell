#include <stdio.h>
#include <stdlib.h>

int* largest_smallest(int arr[], int size) {
  int* res = malloc(2 * sizeof(int));
  int max; 
  int min; 
  res[0] = max;
  res[1] = min;
  int l = 0;
  int r  = 0;
  for (int i = 0; i < size; i++) {
    if (arr[l] > max) {
      max = arr[l];
    }
    l++;
    if (arr[r] < min) {
      min = arr[r];
    }
    r++;
  }
  return res;
}

int main() {
  int arr[] = {34, 12, 56, 223, 76, 43, 90};
  int size = sizeof(arr) / sizeof(arr[0]);
  int* res = largest_smallest(arr, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  for (int i = 0; i < 2; i++) {
    printf("%d ", res[i]);
  }
}
