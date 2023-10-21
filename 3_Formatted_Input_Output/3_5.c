//Exercise 3.5
/*
        Write a program that asks the user to enter the numbers from 1 to 16 (in any order) and then
        displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, columns,
        and diagonals:

*/


#include<stdio.h>

int main(void)
{
    int n_1, n_2, n_3, n_4;
    int n_5, n_6, n_7, n_8;
    int n_9, n_10, n_11, n_12;
    int n_13, n_14, n_15, n_16;

    // 16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1 //
    printf("Enter the numbers from 1 to 16 in any order: \n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &n_1, &n_2, &n_3, &n_4, 
                                                &n_5, &n_6, &n_7, &n_8, 
                                                &n_9, &n_10, &n_11, &n_12, 
                                                &n_13, &n_14, &n_15, &n_16);

    printf("\n%-5d %-5d %-5d %-5d", n_1, n_2, n_3, n_4);
    printf("\n%-5d %-5d %-5d %-5d", n_5, n_6, n_7, n_8);
    printf("\n%-5d %-5d %-5d %-5d", n_9, n_10, n_11, n_12);
    printf("\n%-5d %-5d %-5d %-5d", n_13, n_14, n_15, n_16);
                                              
    int sum_row1 = n_1  + n_2  + n_3  + n_4;
    int sum_row2 = n_5  + n_6  + n_7  + n_8;
    int sum_row3 = n_9  + n_10 + n_11 + n_12;
    int sum_row4 = n_13 + n_14 + n_15 + n_16;

    int sum_columns1 = n_1 + n_5 + n_9 + n_13;
    int sum_columns2 = n_2 + n_6 + n_10 + n_14; 
    int sum_columns3 = n_3 + n_7 + n_11 + n_15; 
    int sum_columns4 = n_4 + n_8 + n_12 + n_16; 

    int sum_diagonal_right = n_1 + n_6 + n_11 + n_16;
    int sum_diagonal_left = n_13 + n_10 + n_7 + n_4;


    printf("\n\nRow sums: %d, %d, %d, %d", sum_row1, sum_row2, sum_row3, sum_row4);
    printf("\nColumn sums: %d, %d, %d, %d", sum_columns1, sum_columns2, sum_columns3, sum_columns4);
    printf("\nDiagonal sums: %d, %d", sum_diagonal_right, sum_diagonal_left);

    return 0;
}