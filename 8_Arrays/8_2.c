// Exercise 8.2

/*
 *
 *       Modify the repdigit.c program of Section 8.1 so that it prints a table
 * showing how many times each digit appears in the number:
 *      Enter a number: 41271092
 *      Digit:       0  1  2  3  4  5  6  7  8  9
 *      Occurrences: 1  2  2  0  1  0  0  1  0  1
 *
 */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  enum { SIZE = 10 };
  int digit_seen[SIZE] = {0};
  long num = 0L;

  printf("Enter a number: ");
  scanf("%ld", &num);

  while (num > 0) {
    digit_seen[num % 10]++;
    num /= 10;
  }

  printf("digit: %9d", 0);
  for (int col = 1; col < SIZE; col++) {
    printf("%3d", col);
  }
  printf("\nOccurrences: ");

  for (int index = 0; index < SIZE; index++) {
    printf("%3d", digit_seen[index]);
  }

  putchar('\n');

  return 0;
}
