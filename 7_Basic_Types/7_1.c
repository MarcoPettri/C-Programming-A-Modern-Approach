// Exercise 7.1


/*
    The square2.c program of Section 6.3 will fail (usually by printing strange answers) if i*i exceeds the maximum int value.
    Run the program and determine the smallest value of n  that  causes  failure.  
    Try  changing  the  type  of  i  to  short  and  running  the  program again. 
    (Don't forget to update the conversion specifications in the call of printf!) Then try long. 
    From these experiments, what can you conclude about the number of bits used to store integer types on your machine?

*/


#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
int main(void){

    uint64_t number = 1;


    for(; number * number < SHRT_MAX; ++number);
    printf("Smallest n causing failure with short: %" PRIu64 "  (square = %" PRIu64 ", SHRT_MAX = %d)\n",
           number, number * number, SHRT_MAX);
    
    for(; number* number  < INT_MAX ; ++number);
    printf("Smallest n causing failure with int: %" PRIu64 "  (square = %" PRIu64 ", INT_MAX = %d)\n",
           number, number * number, INT_MAX);


    for(; number * number < LONG_MAX; ++number);
    printf("Smallest n causing failure with long: %" PRIu64 "  (square = %" PRIu64 ", LONG_MAX = %ld)\n\n",
           number, number * number, LONG_MAX);

    printf("The number of bits used to store integer types:\n");
    printf("sizeof(short)\t= %zu bytes\n", sizeof(short));
    printf("sizeof(int)\t= %zu bytes\n", sizeof(int));
    printf("sizeof(long)\t= %zu bytes\n", sizeof(long));
    
    return 0;
}

