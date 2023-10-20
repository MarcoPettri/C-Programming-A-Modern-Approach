/*
Exercise 2.2:

    Write a program that computes the volume of a sphere with a 10-meter radius, using the formula v = 4/3πr3 . 
     Write the fraction 4/3 as 4.0f/3.0f. (Try writing it as 4/3. What happens?) Hint:
      C doesn’t have an exponentiation operator, so you’ll need to multiply r by itself
      twice to compute r3
.

*/

#include<stdio.h>

#define PI 3.14159
#define RADIUS 10.0
#define V_FORMULA 4.0f / 3.0f * PI * RADIUS * RADIUS * RADIUS

int main(void)
{

    printf("The Volume of a sphere with 10-meter radius is: %.3f", V_FORMULA);

    return 0;
}