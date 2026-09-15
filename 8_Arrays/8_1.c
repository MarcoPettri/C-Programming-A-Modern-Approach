// Exercise 8.1

/*
 *  Modify the repdigit.c program of Section 8.1 so that it shows which digits
 *  (if any) were repeated:
 *      Enter a number: 939577
 *      Repeated digit(s): 7 9

*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
  enum { SIZE = 11 };
  int digit_seen[SIZE] = {0};
  int digit = 0;
  long num = 0L;

  printf("Enter a number: ");
  scanf("%ld", &num);

  while (num > 0) {
    digit = num % 10;
    num /= 10;
    int *count = &digit_seen[digit];

    if (++(*count) == 2) {
      if (digit_seen[SIZE - 1]) {
        printf(" %d", digit);
      } else {
        printf("Repeated digit(s): %d", digit);
        digit_seen[SIZE - 1] = 1;
      }
    }
  }

  putchar('\n');

  return 0;
}
