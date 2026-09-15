// Exercise 9.1

/*
        Write a program that asks the user to enter a series of integers (which
   it stores in an array), then sorts the integers by calling the function
   selection_sort. When given an array with n elements, selection_sort must do
   the following:
            1. Search the array to find the largest element, then move it to the
   last position in the array.
            2. Call itself recursively to sort the first n – 1 elements of the
   array.
*/

#include <stdio.h>

void selection_sort(int[], int size);
void print_array(const int[], int size);

int main() {
  enum { SIZE = 10 };

  int arr[SIZE] = {};

  printf("Enter %d integers\n>>> ", SIZE);

  for (int *ptr = &arr[0]; ptr != &arr[SIZE]; ptr++) {
    scanf("%d", ptr);
  }

  selection_sort(arr, SIZE);

  printf("Sorted array: ");
  print_array(arr, SIZE);
  putchar('\n');

  return 0;
}

void selection_sort(int arr[], int size) {

  if (!size) {
    return;
  }

  int *last = &arr[size - 1];

  for (int *ptr = &arr[0]; ptr != &arr[size]; ptr++) {
    if (*ptr > *last) {
      int temp = *last;
      *last = *ptr;
      *ptr = temp;
    }
  }

  return selection_sort(arr, size - 1);
}

void print_array(const int arr[], int size) {
  for (const int *ptr = &arr[0]; ptr != &arr[size]; ptr++) {
    printf("%2d ", *ptr);
  }
}
