// Exercise 16.6

/*

    Write the following function, assuming that the time structure contains
   three members: hours, minutes, and seconds (all of type int). struct time
   split_time(long total_seconds); total_seconds is a time represented as the
   number of seconds since midnight. The function returns a structure containing
   the equivalent time in hours (0–23), minutes (0–59), and seconds (0–59).

*/

#include <stdio.h>

struct time {
  int hours;
  int minutes;
  int seconds;
};

struct time split_time(long total_seconds) {
  struct time t;
  t.hours = (total_seconds / 3600) % 24;
  t.minutes = (total_seconds % 3600) / 60;
  t.seconds = total_seconds % 60;
  return t;
}

int main(void) {
  struct time t1 = split_time(3661);
  struct time t2 = split_time(86399);
  struct time t3 = split_time(86399 + 1);
  printf("Hours: %d, Minutes: %d, Seconds: %d\n", t1.hours, t1.minutes,
         t1.seconds);
  printf("Hours: %d, Minutes: %d, Seconds: %d\n", t2.hours, t2.minutes,
         t2.seconds);
  printf("Hours: %d, Minutes: %d, Seconds: %d\n", t3.hours, t3.minutes,
         t3.seconds);
  return 0;
}
