// Exercise 3.2
/*
        Write a program that formats product information entered by the user. A session with the
        program should look like this:

                        Enter item number: 583
                        Enter unit price: 13.5
                        Enter purchase date (mm/dd/yyyy): 10/24/2010

                        Item     Unit       Purchase
                                 Price      Date
                        583      $13.50     10/24/2010

        The item number and date should be left justified; the unit price should be right justified.
        Allow dollar amounts up to $9999.99. Hint: Use tabs to line up the columns.
*/


#include<stdio.h>

int main(void)
{
    int   number;
    float price;
    int   mm, dd, yyyy;

    printf("Enter item number: ");
    scanf("%d", &number);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    
    printf("Item\t Unit \t\t Purchase\n");
    printf("\t Price \t\t Date\n");
    printf("%d\t $%.2f \t %d/%d/%d", number, price, mm, dd, yyyy);

    return 0;
}