// Exercise 4.2
/*
        Extend the program in Programming Project 1 to handle three-digit numbers
*/



#include<stdio.h>

int main(void)
{

    int num;

    printf("Enter three-digit number: ");
    scanf("%d", &num);

    int reverse_num = (num % 10 * 100)  + (num / 10 % 10 * 10) + (num / 100);

    printf("The reversal is: %d", reverse_num);
    
    return 0;
}