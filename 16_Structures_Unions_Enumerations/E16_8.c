// Exercise 16.8

/*
Let color be the following structure:
    struct color {
    int red;
    int green;
    int blue;
    };

(a) Write a declaration for a const variable named MAGENTA of type struct color
whose members have the values 255, 0, and 255, respectively.

(b) (C99) Repeat part (a), but use a designated initializer that doesn't specify
the value of green, allowing it to default to 0.



*/

#include <stdio.h>

int main(void) {
  struct color {
    int red;
    int green;
    int blue;
  };

  struct color MAGENTA = {255, 0, 255};

  struct color MAGENTA_C99 = {.red = 255, .blue = 255};

  printf("MAGENTA = %d/%d/%d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);
  printf("MAGENTA_C99 = %d/%d/%d\n", MAGENTA_C99.red, MAGENTA_C99.green,
         MAGENTA_C99.blue);

  return 0;
}
