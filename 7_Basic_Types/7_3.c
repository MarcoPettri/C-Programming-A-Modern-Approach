// Exercise 7.3

/*
    Modify the sum2.c program of Section 7.1 to sum a series of double values.

*/
#include <stdio.h>
#include <math.h>


int main(void){
    const long double EPS = 1e-14L; //
    long double sum = 0L;
    long double n = 0L;

    printf("This program sums a series of Real Number.\n");
    printf("Enter real numbers (0 to terminate): ");
    scanf("%Lf", &n);

    while (fabsl(n) > EPS) {
        sum +=n ;
        scanf("%Lf", &n);
    }
    printf("The sum is: %.4Lf\n", sum);

    return 0;
}

