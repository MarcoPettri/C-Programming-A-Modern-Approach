// Exercise 6.2

/*
    Write a program that asks the user to enter two integers, then calculates and displays
    their greatest common divisor (GCD):

        Enter two integers: 12 28
        Greatest common divisor: 4
        
    Hint: The classic algorithm for computing the GCD, known as Euclid’s algorithm, goes as follows: 
    Let m and n be variables containing the two numbers. If n is 0, then stop: m contains the GCD. 
    Otherwise, compute the remainder when m is divided by n. Copy n into m and copy the remainder into n. 
    Then repeat the process, starting with testing whether n is 0.

*/

#include <stdio.h>

// Return GCD(a, b)
int gcd(int a, int b){

    while( b!=0 ){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {

    int num1;
    int num2;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Greatest common divisor: %d", gcd(num1, num2));
    return 0;
}
