// Exercise 5.2
/*
        Write a program that asks the user for a 24-hour time, then displays the time in 12-hour
        form:
                Enter a 24-hour time: 21:11
                Equivalent 12-hour time: 9:11 PM
        Be careful not to display 12:00 as 0:00.

*/



#include<stdio.h>


int main(void)
{
    int hour, min;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    hour %= 12;
    
    if(hour)
        printf("Equivalent 12-hour time: %d", hour);
    else
        printf("Equivalent 12-hour time: 00");

    if(min)
        printf(":%d PM", min);
    else
        printf(":00 PM");

    return 0;
}