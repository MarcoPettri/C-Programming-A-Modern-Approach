//Exercise 7.5


/*
     In the SCRABBLE Crossword Game, players form words using small tiles, each containing a letter and a face value. 
     The face value varies from one letter to another, based on the letter's rarity. 
     (Here are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ.) 
     Write a program that computes the value of a word by summing the values of its letters:
    
        Enter a word: pitfall
        Scrabble value: 12
        
    Your  program  should  allow  any  mixture  of  lower-case  and  upper-case  letters  in  the  word.
    Hint: Use the toupper library function.

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#include <uchar.h>

int main(void){

    const int_fast8_t score[26] = {
        /*A*/1, /*B*/3, /*C*/3, /*D*/2, /*E*/1,
        /*F*/4, /*G*/2, /*H*/4, /*I*/1, /*J*/8,
        /*K*/5, /*L*/1, /*M*/3, /*N*/1, /*O*/1,
        /*P*/3, /*Q*/10,/*R*/1, /*S*/1, /*T*/1,
        /*U*/1, /*V*/4, /*W*/4, /*X*/8, /*Y*/4,
        /*Z*/10
    };

    int_fast8_t sum = 0;
    int_fast8_t input;

    printf("Enter a word: ");

    while((input = getchar()) != '\n'){

        
        input = isalpha(input)  ? toupper(input) : input;
        
        if(input >= 'A' && input <= 'Z'){
            sum += score[input - 'A'];
        }
    }
    printf("Scrabble value: %" PRIdFAST8 "\n", sum);
    return 0;
}
