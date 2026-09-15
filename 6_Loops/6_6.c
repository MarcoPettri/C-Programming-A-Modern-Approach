// Exercise 6.6

/*
    Write  a  program  that  prompts  the  user  to  enter  a  number  n,  
    then  prints  all  even  squares between 1 and n. 
    For example, if the user enters 100, the program should print the following:
    
        4
        16
        36
        64
        100

*/
#include <stdio.h>

int main() {

    int num;
    
    printf("Enter a natural number greater than 1: ");
    scanf("%d", &num);

    for(int square = 4, increment = 12; 
            square <= num; 
            square += increment, increment += 8){

        printf("%d\n", square);
    }
    return 0;
}
