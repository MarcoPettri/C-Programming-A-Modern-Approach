/*
Exercise 2.5:
    Write a program that asks the user to enter a value for x and then displays the value of the
     following polynomial:

            3x^5 + 2x^4 -5x^3 -x^2 + 7x -6

    Hint: C doesn't have an exponentiation operator, so you'll need to multiply x by itself
    repeatedly in order to compute the powers of x. (For example, x * x * x is x cubed.)

*/

#include<stdio.h>

int main(void)
{

    int coeff_5  =  3;
    int coeff_4  =  2; 
    int coeff_3  = -5;  
    int coeff_2  = -1;
    int coeff_l  =  7;
    int constant = -6;
    int x;


    printf("3x^5 + 2x^4 -5x^3 -x^2 + 7x -6\n");
    printf("Enter a value for x: ");
    scanf("%d", &x);

    int result =  coeff_5*(x*x*x*x*x) +  coeff_4*(x*x*x*x)  + coeff_3*(x*x*x) + coeff_2*(x*x) + coeff_l*(x) + constant;
    printf("Result: %d", result);

    

}