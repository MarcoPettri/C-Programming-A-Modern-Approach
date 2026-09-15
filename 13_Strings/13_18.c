// Exercise 13.18

/*

    Write a program that accepts a date from the user in the form mm/dd/yyyy and
   then dis- plays it in the form month dd, yyyy, where month is the name of the
   month:

        Enter a date (mm/dd/yyyy): 2/17/2011
        You entered the date February 17, 2011

    Store the month names in an array that contains pointers to strings.

*/

#include <stdio.h>

int main(void) {
  const char *months[13] = {
      "NONE", "January", "February",  "March",   "April",    "May",      "June",
      "July", "August",  "September", "October", "November", "December",
  };
  char fmt[] = "You entered the date %s %d, %d\n";

  int month = 0, day = 0, year = 0;
  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%d/%d/%d", &month, &day, &year);

  if (month < 1 || month > 12)
    month = 0;

  printf(fmt, months[month], day, year);

  return 0;
}
