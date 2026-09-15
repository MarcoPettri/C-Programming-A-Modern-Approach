// Exercise 7.7

/*
    Modify Programming Project 6 from Chapter 3 so that the user may add,
   subtract, multiply, or divide two fractions (by entering either +, -, *, or /
   between the fractions).

*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int, int);

int main(void) {

  int num1 = 0;   // 3
  int denom1 = 0; // 2;
  int num2 = 0;   // 5;
  int denom2 = 0; // 7;

  long result_num = 0;
  long result_denom = 0;

  char operator = '\0';

  printf("Enter two fractions (a/b) separated by any operador (+, -, *, /): ");
  scanf("%d/%d%c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

  if (!denom1 || !denom2) {
    printf("ZeroDivisionError\n");
    return EXIT_FAILURE;
  } else if (!num1 || !num2) {
    if (num1) {
      result_num = num1;
      result_denom = denom1;
    } else {
      result_num = num1;
      result_denom = denom2;
    }
  } else {
    switch (operator) {
    case '+':
      result_num = (num1 * denom2) + (num2 * denom1);
      break;
    case '-':
      result_num = (num1 * denom2) - (num2 * denom1);
      break;
    case '*':
    case '/':
      if (operator == '/') {

        int temp = num2;
        num2 = denom2;
        denom2 = temp;
      }
      result_num = num1 * num2;
      break;
    default:
      printf("INVALID OPERATIONS: %c\n", operator);
      return EXIT_FAILURE;
    }

    result_denom = denom1 * denom2;
    const int GCD = gcd(result_num, result_denom);
    result_num /= GCD;
    result_denom /= GCD;
  }

  if (result_denom != 1) {
    printf("Result: %ld/%ld\n", result_num, result_denom);
  } else {
    printf("Result: %ld\n", result_num);
  }

  return 0;
}

int gcd(int a, int b) {

  if (!a || !b) {
    return a ? !b : b;
  }

  a = abs(a);
  b = abs(b);
  while (b) {
    int t = a % b;
    a = b;
    b = t;
  }

  return a;
}
