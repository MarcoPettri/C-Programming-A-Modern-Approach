// Exercise 12.2

/*
    (a) Write a program that reads a message, then checks whether it’s a
   palindrome (the lettersvin the message are the same from left to right as
   from right to left):

            Enter a message: He lived as a devil, eh?
            Palindrome

            Enter a message: Madam, I am Adam.
            Not a palindrome


    Ignore all characters that aren’t letters. Use integer variables to keep
   track of positions in the array.

    (b) Revise the program to use pointers instead of integers to keep track of
   positions in the array.

*/

#include "MyString.h"
#include <stdio.h>

int main(void) {
  String input = string_create();

  printf("Enter a message: ");
  fflush(stdout);

  if (!string_read_line(&input)) {
    printf("\n(nothing read / EOF)\n");
    string_free(&input);
    return 0;
  }

  char *it_begin = string_begin(&input);
  char *it_rbegin = string_rbegin(&input);
  char *it_end = string_end(&input);
  char *it_rend = string_rend(&input);
  while (it_begin != it_end || it_rbegin != it_rend) {
    if (*it_begin != *it_rbegin) {
      printf("Not a palindrome\n");
      string_free(&input);
      return 0;
    }
    it_begin++;
    it_rbegin--;
  }
  printf("Palindrome\n");
  string_free(&input);
  return 0;
}
