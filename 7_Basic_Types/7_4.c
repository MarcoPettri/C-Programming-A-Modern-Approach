// Exercise 7.4

/*
    Write a program that translates an alphabetic phone number into numeric form:
    
        Enter phone number: CALLATT
        2255288
        
    (In case you don't have a telephone nearby, here are the letters on the keys: 2=ABC, 3=DEF,
    4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original phone number contains
    nonalphabetic characters (digits or punctuation, for example), leave them unchanged:
    
        Enter phone number: 1-800-COL-LECT
        1-800-265-5328
        
    You may assume that any letters entered by the user are upper case.

*/
#include <stdio.h>
#include <uchar.h>
#include <ctype.h>


int main(void){

    const char16_t map[26] = {
        '2','2','2',   // A B C
        '3','3','3',   // D E F
        '4','4','4',   // G H I
        '5','5','5',   // J K L
        '6','6','6',   // M N O
        '7', 'Q','7','7',   // P Q R S
        '8','8','8',   // T U V
        '9','9','9','Z'  // W X Y Z
    };

    printf("Enter phone number: ");
    int input;
    
    while((input = getchar()) != '\n'){
        
        if(isalpha(input) && input >= 'A' && input <= 'Z'){
            input = map[input - 'A'];
        }
        putchar(input);
    }

    putchar('\n');
    return 0;
}



