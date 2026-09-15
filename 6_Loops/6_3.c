// Exercise 6.3

/*
    Write  a  program  that  asks  the  user  to  enter  a  fraction,  
    then  reduces  the  fraction  to  lowest terms:

        Enter a fraction: 6/12
        In lowest terms: 1/2
        
    Hint:  To  reduce  a  fraction  to  lowest  terms,  first  compute  the  GCD  of  the  numerator  and denominator. 
    Then divide both the numerator and denominator by the GCD.

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

    int numerator;
    int denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    int greatest_cd = gcd(numerator, denominator);

    numerator /= greatest_cd;
    denominator /= greatest_cd;

    printf("In lowest terms: %d/%d", numerator, denominator);

    return 0;
}
