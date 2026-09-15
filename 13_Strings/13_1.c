// Exercise 13.1

/*
    Write a program that finds the “smallest” and “largest” in a series of
   words. After the user enters the words, the program will determine which
   words would come first and last if the words were listed in dictionary order.
   The program must stop accepting input when the user enters a four-letter
   word. Assume that no word is more than 20 letters long. An interactive
    session with the program might look like this:

            Enter word: dog
            Enter word: zebra
            Enter word: rabbit
            Enter word: catfish
            Enter word: walrus
            Enter word: cat
            Enter word: fish
            Smallest word: cat
            Largest word: zebra

    Hint: Use two strings named smallest_word and largest_word to keep track of
   the “smallest” and “largest” words entered so far. Each time the user enters
   a new word, use strcmp to compare it with smallest_word; if the new word is
   “smaller,” use strcpy to save it in smallest_word. Do a similar comparison
   with largest_word. Use strlen to determine when the user has entered a
   four-letter word.


*/

#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 21 // 20 letters + '\0'

bool check(char *str);

int main(void) {
  char input[MAX_LEN];
  char largest_word[MAX_LEN] = "";
  char smallest_word[MAX_LEN] = "";
  bool first = true;

  printf("Enter word: ");
  while (check(input)) {
    if (first) {
      strcpy(largest_word, input);
      strcpy(smallest_word, input);
      first = false;
    } else {
      if (strcmp(input, largest_word) > 0) {
        strcpy(largest_word, input);
      }
      if (strcmp(input, smallest_word) < 0) {
        strcpy(smallest_word, input);
      }
    }
    printf("Enter word: ");
  }

  printf("\nSmallest word: %s", smallest_word);
  printf("\nLargest word: %s\n", largest_word);
  return 0;
}

bool check(char *str) {
  if (scanf("%20s", str) != 1) {
    return false;
  }

  regex_t regex;
  if (regcomp(&regex, "^([[:alpha:]]{1,3}|[[:alpha:]]{5,20})$", REG_EXTENDED) !=
      0) {
    printf("Error compiling the regular expression\n");
    exit(1);
  }

  int result = regexec(&regex, str, 0, NULL, 0);
  regfree(&regex);
  return result == 0;
}
