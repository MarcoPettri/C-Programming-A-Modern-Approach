// Exercise 13.4

/*

    Write a program named reverse.c that echoes its command-line arguments in
   reverse order. Running the program by typing

        reverse void and null

    should produce the following output:

        null and void

*/

#include <stdio.h>

int main(int argc, char **argv) {

  for (char **arg = &argv[argc - 1]; argc > 1; --argc, --arg) {
    printf("%s ", *arg);
  }
  putchar('\n');
  return 0;
}
