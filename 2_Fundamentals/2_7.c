/*
Exercise 2.7:
    Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
     that amount using the smallest number of $20, $10, $5, and $1 bills:

                Enter a dollar amount: 93
                    $20 bills: 4
                    $10 bills: 1
                    $5  bills: 0
                    $1  bills: 3

    Hint: Divide the amount by 20 to determine the number of $20 bills needed, and then reduce
    the amount by the total value of the $20 bills. Repeat for the other bill sizes. Be sure to use
    integer values throughout, not floating-point numbers.

*/

#include<stdio.h>

int main(void)
{
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int bills_20 = 0; 
    int bills_10 = 0; 
    int bills_5 = 0; 
    int bills_1 = 0;
    
    
    while(amount >= 20){
        amount -= 20;
        bills_20 += 1;
    }
    while(amount >= 10){
        amount -= 10;
        bills_10 += 1;
    }
    while(amount >= 5){
        amount -= 5;
        bills_5 += 1;
    }
    while(amount >= 1){
        amount -= 1;
        bills_1 += 1;
    }

    printf("\n$20 bills: %d", bills_20);
    printf("\n$10 bills: %d", bills_10);
    printf("\n$5  bills: %d", bills_5);
    printf("\n$1  bills: %d", bills_1);
    
    return 0;
}