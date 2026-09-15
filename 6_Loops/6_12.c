// Exercise 6.12

/*

    Modify Programming Project 11 so that the program continues adding terms until the current  
    term  becomes  less  than  ε,  where  ε  is  a  small  (floating-point)  number  entered  by  the user.

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

    double epsilon; 
    
    printf("Enter epsilon (e.g. 0.0001):  ");
    scanf("%lf", &epsilon);
    
    double aprox = 1.0;
    double term = 1.0;
    for(int n = 2; epsilon < term; ++n){
        aprox += term;
        term = 1.0 / factorial(n);
    }

    printf("Approximation of e: %.10f\n", aprox);
    return 0;
}