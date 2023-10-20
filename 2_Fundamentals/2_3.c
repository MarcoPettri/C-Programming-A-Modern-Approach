/*
Exercise 2.3:
    Modify the program of Programming Project 2 so that it prompts the user to enter the radius
     of the sphere

*/

#include<stdio.h>

#define PI 3.14159
#define V_FORMULA 4.0f / 3.0f * PI 

int main(void)
{
    int radius;
    
    printf("Enter the radius: ");
    scanf("%d", &radius);
    printf("The Volume of a sphere with %d-meter radius is: %.3f", radius,  V_FORMULA * radius * radius * radius);

    return 0;
}