// Exercise 4.4
/*
        Write a program that reads an integer entered by the user and displays it in octal (base 8):
                Enter a number between 0 and 32767: 1953
                In octal, your number is: 03641
        The output should be displayed using five digits, even if fewer digits are sufficient. 

*/

#include<stdio.h>



int main()
{   
    int num;
    int octal_num = 0;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &num);


    for(int i = 0, place = 1; i < 5; ++i, place *= 10){
        octal_num += num % 8 * place;
        num /= 8;
    }

    if(octal_num / 10000){

        printf("In octal, your number is: %d", octal_num);
    }
    else{
    }   printf("In octal, your number is: 0%d", octal_num);


    return 0;
}


