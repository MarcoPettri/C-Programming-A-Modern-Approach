// Exercise 7.2


/*
    Modify the square2.c program of Section 6.3 so that it pauses after every 24 squares and
    displays the following message:

        Press Enter to continue...
        
    After  displaying  the  message,  the  program  should  use  getchar  to  read  a  character.
    getchar won't allow the program to continue until the user presses the Enter key.

*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(void){

    int64_t n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");

    scanf("%" SCNd64, &n);
    while (getchar() != '\n');

    for (int64_t i = 1; i <= n; ++i) {
        printf("%10" PRId64 "%10" PRId64 "\n", i, i * i);

        if (!(i % 24)) {
            printf("Press Enter to continue... ");
            while (getchar() != '\n');
        }
    }
    return 0;
}

