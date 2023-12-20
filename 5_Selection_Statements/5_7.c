// Exercise 5.7
/*

        Write a program that finds the largest and smallest of four integers entered by the user:
                Enter four integers: 21 43 10 35
                Largest: 43
                Smallest: 10
        Use as few if statements as possible. Hint: Four if statements are sufficient.
*/


#include<stdio.h>

int main(void)
{
    int const SIZE = 4;
    int integers[SIZE];

    printf("Enter four integers\n");
    for(int i = 0; i < SIZE; ++i){
        printf("-> ");
        scanf("%d", &integers[i]);
    
    }

    int* smallest = &integers[0];
    int* largest = &integers[ SIZE -1];

    int const* cbegin = &integers[0];
    const int *const cend = &integers[SIZE];

    for(; cbegin != cend; ++cbegin){

        if(*cbegin > *largest){
            *largest = *cbegin;
        }
        if(*cbegin < *smallest){
            *smallest = *cbegin;
        }
    }

    printf("Largest: %d", *largest);
    printf("\nSmallest: %d", *smallest);

    return 0;
}