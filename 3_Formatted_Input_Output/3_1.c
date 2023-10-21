// Exercise 3.1
/*
        Write a program that accepts a date from the user in the form mm/dd/yyyy and then dis-
        plays it in the form yyyymmdd

*/  

#include<stdio.h>

int main(void)
{

    int mm,dd,yyyy;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("You entered the date: %d%.2d%d", yyyy, mm, dd);

    return 0;
}