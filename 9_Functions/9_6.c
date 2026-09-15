// Exercise 9.6

/*
        Write a function that computes the value of the following polynomial:
            3x^5 + 2x^4 -5x^3 -x^2 + 7x -6
        Write a program that asks the user to enter a value for x, calls the
   function to compute the value of the polynomial, and then displays the value
   returned by the function.
*/

#include <stdio.h>

double horner_method(const double coeff[], int degree, double x);

int main() {
  // const double coefficients = {3., 2., -5., -1., 7., -6.};
  double var = 0;
  printf("Polynomal: 3x^5 + 2x^4 -5x^3 -x^2 + 7x -6\n");
  printf("Enter a value for x: ");
  scanf("%lf", &var);

  double result = horner_method((const double[]){3, 2, -5, -1, 7, -6}, 5, var);

  printf("Result %.3lf\n", result);

  return 0;
}

double horner_method(const double coeff[], int degree, double x) {
  double result = coeff[0];

  for (int i = 1; i <= degree; i++) {
    result = result * x + coeff[i];
  }
  return result;
}
