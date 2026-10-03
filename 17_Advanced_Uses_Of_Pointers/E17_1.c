// Exercise: E17.1

/*

    Having to check the return value of malloc (or any other memory allocation
    function) each time we call it can be an annoyance. Write a function named
    my_malloc that serves as a “wrapper” for malloc. When we call my_malloc and
   ask it to allocate n bytes, it in turn calls malloc, tests to make sure that
   malloc doesn’t return a null pointer, and then returns the pointer from
   malloc. Have my_malloc print an error message and terminate the program if
   malloc returns a null pointer.

*/

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size);

int main(void) {
  int *arr = (int *)my_malloc(1000 * sizeof(int));

  for (int i = 0; i < 1000; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < 1000; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");

  free(arr);

  return 0;
}

void *my_malloc(size_t size) {
  void *ptr;

  if ((ptr = malloc(size)) == NULL) {
    fprintf(stderr, "Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}
