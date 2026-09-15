// Exercise 12.1
/*

    (a) Write a program that reads a message, then prints the reversal of the
   message:

        Enter a message: Don't get mad, get even.
        Reversal is: .neve teg,dam teg t'noD

    Hint: Read the message one character at a time (using getchar)
   and store the characters in an array. Stop reading when the array is full or
   the character read is '\n'.

    (b) Revise the program to use a pointer instead of an integer to keep track
   of the current position in the array.
*/

#include <stdio.h>

#include "MyString.h"

int main(void) {
  String s = string_create();

  printf("Entar a message: ");
  fflush(stdout);

  if (!string_read_line(&s)) {
    printf("\n(nothing read / EOF)\n");
    string_free(&s);
    return 0;
  }

  printf("\nYou typed: \"%s\" \n", string_cstr(&s));

  /* --- reverse iteration --- */
  printf("Reversal is: ");
  for (char *it = string_rbegin(&s); it != string_rend(&s); --it) {
    putchar(*it);
  }
  putchar('\n');
  putchar('\n');

  string_free(&s);
  return 0;
}
