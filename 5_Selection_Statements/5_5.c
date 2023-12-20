// Exercise 5.5
/*
        In one state, single residents are subject to the following income tax:
        Income Amount of tax:

                    Not over $750 1% of income
                    $750–$2,250 $7.50 plus 2% of amount over $750
                    $2,250–$3,750 $37.50 plus 3% of amount over $2,250
                    $3,750–$5,250 $82.50 plus 4% of amount over $3,750
                    $5,250–$7,000 $142.50 plus 5% of amount over $5,250
                    Over $7,000 $230.00 plus 6% of amount over $7,000

        Write a program that asks the user to enter the amount of taxable income, then displays the
        tax due.

*/

#include<stdio.h>

int main(void)
{
    double amount;
    double income_tax;

    printf("Enter the amount: ");
    scanf("%lf", &amount);


    if(amount < 750){
            income_tax = amount * 1.0 / 100.0;
    }
    else if (amount < 2250) {
        income_tax = 7.50   + (amount > 750 ? 7.50 * 2.0 / 100.0 : 0.0);
    }
    else if (amount < 3750) {
        income_tax = 37.50  + (amount > 2250 ? 37.50 * 3.0/ 100.0 : 0.0);
    }
    else if (amount < 5250) {
        income_tax = 82.50  + (amount > 3750 ? 82.50 * 4.00/ 100.0 : 0.0);
    }
    else if (amount < 7000 ) {
        income_tax = 142.50 + (amount > 5250 ? 142.50 * 5.0 / 100.0 : 0.0);
    }
    else{
        income_tax = 230.00 + (amount > 7000 ? 230.00 * 6.0 / 100.0 : 0.0);
    }
    
    printf("Income Tax: %.3lf", income_tax);



    return 0;
}