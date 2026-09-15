/*
Exercise 2.6: 
    Modify the program of Programming Project 5 so that the polynomial is evaluated using the
     following formula:

            ((((3x + 2)x – 5)x  -1)x + 7)x  -6

    Note that the modified program performs fewer multiplications. 
    this technique for evaluating polynomials is known as Horner's Rule.


*/

#include<stdio.h>

int main(void)
{

    double x;
    printf("3x^5 + 2x^4 -5x^3 -x^2 + 7x -6\n");
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    double result = ((((3*x + 2)*x  -5)*x  -1)*x + 7)*x  -6;

    printf("Result: %.2f", result);

    return 0;

}