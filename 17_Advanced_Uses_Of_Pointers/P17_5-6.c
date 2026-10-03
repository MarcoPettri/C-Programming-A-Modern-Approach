// Exercise: P17.5-6

/*

5. Write a program that sorts a series of words entered by the user:

    Enter word: foo
    Enter word: bar
    Enter word: baz
    Enter word: quux
    Enter word:

    In sorted order: bar baz foo quux

Assume that each word is no more than 20 characters long. Stop reading when the
user enters an empty word (i.e., presses Enter without entering a word). Store
each word in a dynamically allocated string, using an array of pointers to keep
track of the strings, as in the remind2.c program (Section 17.2). After all
words have been read, sort the array (using any sorting technique) and then use
a loop to print the words in sorted order. Hint: Use the read_line function to
read each word, as in remind2.c.

*/
/*
6. Modify Programming Project 5 so that it uses qsort to sort the array of
pointers.


*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20
#define INITIAL_CAPACITY 10

int read_line(char str[], int n);
int compare_words(const void *p, const void *q);

int main(void) {
  const char *const MEMORY_ALLOCATION_FAILED_MSG =
      "-- Memory allocation failed --\n";
  const char *const MAX_CAPACITY_REACHED_MSG =
      "-- MAX Words Capacity Reached --\n";

  char **words = NULL; /* dynamically allocated array of pointers */
  size_t capacity = 0;
  size_t num_words = 0;
  char word[WORD_LEN + 1];

  for (;;) {
    printf("Enter word: ");
    if (!read_line(word, WORD_LEN))
      break;

    /* Grow the pointer array when it is full. */
    if (num_words == capacity) {
      size_t new_capacity;

      if (!capacity) {
        new_capacity = INITIAL_CAPACITY;
      } else if (capacity > SIZE_MAX / sizeof(*words) / 2) {
        fprintf(stderr, MAX_CAPACITY_REACHED_MSG);
        break;
      } else {
        new_capacity = capacity * 2;
      }

      char **tmp = realloc(words, new_capacity * sizeof(*words));
      if (!tmp) {
        fprintf(stderr, MEMORY_ALLOCATION_FAILED_MSG);
        break;
      }
      words = tmp;
      capacity = new_capacity;
    }

    words[num_words] = malloc(strlen(word) + 1);
    if (!words[num_words]) {
      fprintf(stderr, MEMORY_ALLOCATION_FAILED_MSG);
      break;
    }
    strcpy(words[num_words], word);
    num_words++;
  }

  if (num_words > 1)
    qsort(words, num_words, sizeof(char *), compare_words);

  printf("\nIn sorted order:");
  for (size_t idx = 0; idx < num_words; idx++)
    printf(" %s", words[idx]);
  printf("\n");

  for (size_t idx = 0; idx < num_words; idx++)
    free(words[idx]);
  free(words);

  return 0;
}

int compare_words(const void *p, const void *q) {
  return strcmp(*(char *const *)p, *(char *const *)q);
}

/* Reads a line into str, storing at most n characters (extra characters are
   discarded). Returns the number of characters stored. */
int read_line(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF)
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
