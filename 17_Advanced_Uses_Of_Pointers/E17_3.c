// Exercise 17.3

/*

Write the following function:

    int *create_array(int n, int initial_value);

The function should return a pointer to a dynamically allocated int array with n
members, each of which is initialized to initial_value. The return value should
be NULL if the array can’t be allocated.

*/

#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value) {

  int *arr = (int *)malloc(n * sizeof(int));

  if (!arr) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = initial_value;
  }

  return arr;
}

int main(void) {

  int *arr = create_array(10, 5);

  if (!arr) {
    fprintf(stderr, "Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}