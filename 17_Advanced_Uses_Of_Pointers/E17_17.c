// Exercise 17.17

/*

Let a be an array of 100 integers. Write a call of qsort that sorts only the
last 50 elements in a. (You don’t need to write the comparison function).

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_ints(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int main(void) {
  int a[100];
  srand(time(NULL));
  for (int i = 0; i < 100; i++) {
    a[i] = rand() % 100;
  }
  for (int i = 0; i < 100; i++) {
    printf("%2d ", a[i]);
    if (!((i + 1) % 10))
      printf("\n");
  }
  printf("\n\n");
  qsort(a + 50, 50, sizeof(int), compare_ints);
  for (int i = 0; i < 100; i++) {
    printf("%2d ", a[i]);
    if (!((i + 1) % 10))
      printf("\n");
  }
  printf("\n");

  return 0;
}
