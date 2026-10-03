// Exercise 17.16

/*

Write the following function. The call sum(g, i, j) should return g(i) + … +
g(j).

    int sum(int (*f)(int), int start, int end);

*/

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

int sum(int (*f)(int), int start, int end);
int square(int x);

int main(void) {
  int (*f)(int) = square;
  printf("%d\n", sum(f, 1, 10));

  return 0;
}

int sum(int (*f)(int), int start, int end) {
  long long result = 0;
  for (int i = start; i <= end; i++) {
    result += f(i);
    if (result > INT_MAX) {
      fprintf(stderr, "Overflow detected\n");
      return INT_MAX;
    } else if (result < INT_MIN) {
      fprintf(stderr, "Underflow detected\n");
      return INT_MIN;
    }
  }
  return (int)result;
}

int square(int x) { return x * x; }