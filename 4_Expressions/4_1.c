// Exercise 4.1
/*
        Write a program that asks the user to enter a two-digit number, then prints the number with
        its digits reversed. A session with the program should have the following appearance:
             Enter a two-digit number: 28
             The reversal is: 82

*/


#include<stdio.h>

int main(void)
{


    int num1;

    printf("Enter a two-digit number: ");
    scanf("%d", &num1);

    int tens = num1 / 10;
    int ones = num1 % 10;
    
    printf("The reversal: %d", ones * 10 + tens);


}