// Exercise 8.7

/*
    Write a program that reads a 5 × 5 array of integers and then prints the row
 sums and the column sums:

        Enter row 1: 8 3 9 0 10
        Enter row 2: 3 5 17 1 1
        Enter row 3: 2 8 6 23 1
        Enter row 4: 15 7 3 2 9
        Enter row 5: 6 14 2 6 0

        Row totals: 30 27 40 36 28
        Column totals: 34 37 37 32 21
 *
*/

#include <stdio.h>

int main(void) {
  enum { SIZE = 5 };
  int array_row[SIZE] = {0};
  int array_col[SIZE] = {0};

  for (int *ptr_row = &array_row[0]; ptr_row != &array_row[SIZE]; ptr_row++) {

    printf("Enter row %td: ", (ptr_row - &array_row[0]) + 1);

    for (int *ptr_col = &array_col[0]; ptr_col != &array_col[SIZE]; ptr_col++) {
      int digit = 0;
      scanf("%d", &digit);
      *ptr_row += digit;
      *ptr_col += digit;
    }
  }

  printf("\nRow totals: ");
  for (int *ptr_row = &array_row[0]; ptr_row != &array_row[SIZE]; ptr_row++) {
    printf("%2d ", *ptr_row);
  }

  printf("\nColumn totals: ");
  for (int *ptr_col = &array_col[0]; ptr_col != &array_col[SIZE]; ptr_col++) {
    printf("%2d ", *ptr_col);
  }
  putchar('\n');

  return 0;
}
