// Exercise 6.11

/*

    The value of the mathematical constant e can be expressed as an infinite series:

        e = 1 + 1/1! + 1/2! + 1/3! + ...

    Write a program that approximates e by computing the value of
    
        1 + 1/1! + 1/2! + 1/3! + ... + 1/n!
        
    where n is an integer entered by the user.

*/
#include <stdio.h>

long long factorial(int num){
    long long result = 1;

    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}

int main() {

    int num; 

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    double aprox = 1.0;
    for(; num >= 1; --num){
        aprox += 1.0 / factorial(num);
    }

    printf("Approximation of e: %.10f\n", aprox);
    return 0;
}

