// Exercise 17.2

/*

    Write a function named duplicate that uses dynamic storage allocation to
   create a copy of a string. For example, the call p = duplicate(str); would
   allocate space for a string of the same length as str, copy the contents of
   str into the new string, and return a pointer to it. Have duplicate return a
   null pointer if the memory allocation fails.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(const char *str) {

  char *new_str = (char *)malloc(strlen(str) + 1);

  return !new_str ? NULL : strcpy(new_str, str);
}

int main(void) {

  char *str1 = "Hello";
  char *str2 = duplicate(str1);

  if (!str2) {
    fprintf(stderr, "Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }

  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);

  free(str2);

  return 0;
}
