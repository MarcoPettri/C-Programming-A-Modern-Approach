// Exercise 3.4
/*
        Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-
        xxxx and then displays the number in the form xxx.xxx.xxx

*/

#include<stdio.h>

int main(void)
{

    int code, area, number;

    printf("Enter phone number (xxx) xxx-xxxx: ");
    scanf("(%d) %d-%d", &code, &area, &number);

    printf("You entered %d.%d.%d", code, area, number);

    return 0;
}