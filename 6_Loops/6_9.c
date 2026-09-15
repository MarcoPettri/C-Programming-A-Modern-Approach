// Exercise 6.9

/*

    Programming  Project  8  in  Chapter  2  asked  you  to  write  a  program  that  calculates  
    the remaining balance on a loan after the first, second, and third monthly payments.
    Modify the program so that it also asks the user to enter the number of payments and then displays 
    the balance remaining after each of these payments.

*/
#include <stdio.h>



int main(void)
{
    int  num;
    float amount_loan;
    float interest_rate;
    float monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &amount_loan);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    printf("What is the numbers of payments?: ");
    scanf("%d", &num);

    interest_rate = interest_rate / 100;
    interest_rate = interest_rate / 12;

    float balance = amount_loan - monthly_payment + (amount_loan * interest_rate);
    for(int n_payment = 1; n_payment  <= num; ++n_payment){

        printf("Balance remaining after ");

        if ((n_payment % 10  == 1) && ( n_payment % 100 != 11)) {
            printf("%dst ", n_payment);
        }
        else if ((n_payment % 10  == 2) && (n_payment % 100 != 12)) {
            printf("%dnd ", n_payment);
        }
        else if ((n_payment % 10  == 3) && (n_payment % 100 != 13)) {
            printf("%drd ", n_payment);
        }
        else{
             printf("%dth ", n_payment);
        }
        printf("payment: $%.2f\n", balance);
        balance = balance - monthly_payment + (balance * interest_rate);
    }

    


    return 0;
}
