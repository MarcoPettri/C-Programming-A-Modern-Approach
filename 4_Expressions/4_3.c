// Exercise 4.3
/*

    Rewrite the program in Programming Project 2 so that it prints the reversal of a three-digit
    number without using arithmetic to split the number into digits
*/

#include<stdio.h>

int main()
{
    int hundreds, tens, ones;

    printf("Enter three-digit number: ");
    scanf("%1d%1d%1d", &hundreds, &tens, &ones);

    printf("The reversal is: %d%d%d", ones, tens, hundreds);




    return 0;
}