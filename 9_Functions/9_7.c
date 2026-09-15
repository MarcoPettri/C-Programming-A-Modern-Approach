// Exercise 9.7

/*
          The power function of Section 9.6 can be made faster by having it
   calculate x^n in a different way. We first notice that if n is a power of 2,
   then x^n can be computed by squarin. For example, x^4 is the square of x^2,
   so x^4 can be computed using only two multiplications instead of three. As it
   happens, this technique can be used even when n is not a power of 2. If n is
   even, we use the formula

            x^n = (x^{n/2})^2.

   If n is odd, then

            x^n = x × x^{n-1}.

   Write a recursive function that computes x^n. (The recursion ends when n = 0,
   in which case the function returns 1.) To test your function, write a program
   that asks the user to enter values for x and n, calls power to compute x^n,
   and then displays the value returned by the function.
*/

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int64_t power(int64_t base, int64_t exp);

int main(void) {
  int64_t number = 0;
  int64_t exponent = 0;

  printf("Enter a base x and exponent n:\nx = ");

  scanf("%" SCNd64, &number);

  printf("n = ");
  scanf("%" SCNd64, &exponent);

  int64_t result = power(number, exponent);
  printf("x^n = %" PRId64 "\n", result);
  return 0;
}

int64_t power(int64_t base, int64_t exp) {
  if (!exp) {
    return 1;
  } else if (exp & 1) { // exp is odd
    return base * power(base, exp - 1);
  }
  int64_t result = power(base, exp / 2);
  return result * result;
}
