// Exercise: 16_5
/*
    Write the following functions, assuming that the date structure contains
   three members: month, day, and year (all of type int). (a) int
   day_of_year(struct date d); Returns the day of the year (an integer between 1
   and 366) that corresponds to the date d.

    (b) int compare_dates(struct date d1, struct date d2);
    Returns –1 if d1 is an earlier date than d2, +1 if d1 is a later date than
   d2, and 0 if d1 and d2 are the same

*/

#include <assert.h>
#include <stdio.h>

typedef struct date {
  int month;
  int day;
  int year;
} Date;

const int DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(Date d);
int compare_dates(Date d1, Date d2);

int main(void) {
  Date date_1 = {9, 29, 2025};
  Date date_2 = {10, 1, 2025};
  Date date_3 = {12, 31, 2025};

  printf("date_1: %d %d %d\n", date_1.month, date_1.day, date_1.year);
  printf("date_2: %d %d %d\n", date_2.month, date_2.day, date_2.year);
  printf("date_3: %d %d %d\n", date_3.month, date_3.day, date_3.year);

  printf("day of year of date_1: %d\n", day_of_year(date_1));
  printf("day of year of date_2: %d\n", day_of_year(date_2));
  printf("day of year of date_3: %d\n", day_of_year(date_3));

  printf("compare_dates(date_1, date_2): %d\n", compare_dates(date_1, date_2));
  printf("compare_dates(date_2, date_1): %d\n", compare_dates(date_2, date_1));
  printf("compare_dates(date_3, date_1): %d\n", compare_dates(date_3, date_1));
  printf("compare_dates(date_1, date_1): %d\n", compare_dates(date_1, date_1));

  return 0;
}

int day_of_year(Date d) {
  assert(d.month >= 1 && d.month <= 12 && d.day >= 1 && d.day <= 31);
  int day_counter = 0;
  for (int temp_month = 1; temp_month < d.month; temp_month++) {
    day_counter += DAYS_IN_MONTH[temp_month - 1];
  }
  day_counter += d.day;
  return day_counter;
}

int compare_dates(Date d1, Date d2) {
  int day_1 = day_of_year(d1);
  int day_2 = day_of_year(d2);

  if (day_1 < day_2)
    return -1;
  if (day_1 > day_2)
    return 1;
  return 0;
}