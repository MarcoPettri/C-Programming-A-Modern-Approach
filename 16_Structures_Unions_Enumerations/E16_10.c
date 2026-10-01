// Exercise 16.10

/*

The following structures are designed to store information about objects
    on a graphics screen:

    struct point { int x, y; };
    struct rectangle { struct point upper_left, lower_right; };

A point structure stores the x and y coordinates of a point on the screen. A rectangle
structure stores the coordinates of the upper left and lower right corners of a rectangle. Write
functions that perform the following operations on a rectangle structure r passed as an
argument:
    (a) Compute the area of r.

    (b) Compute the center of r, returning it as a point value. If either the x or y coordinate of
        the center isn't an integer, store its truncated value in the point structure.
    
    (c) Move r by x units in the x direction and y units in the y direction, 
        returning the modified version of r. (x and y are additional arguments to the function.)
    
    (d) Determine whether a point p lies within r, returning true or false. 
        (p is an additional argument of type struct point.)

*/

#include <stdbool.h>
#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point upper_left;
  struct point lower_right;
};

int area(struct rectangle r);
struct point center(struct rectangle r);
struct rectangle move(struct rectangle r, int x, int y);
bool contains(struct rectangle r, struct point p);

int main(void) {

  struct rectangle r = {.upper_left = {.x = 0, .y = 0},
                        .lower_right = {.x = 10, .y = 10}};
  struct point p = {.x = 5, .y = 5};
  struct point p2 = {.x = 15, .y = 15};

  printf("Area: %d\n", area(r));
  printf("Center: %d %d\n", center(r).x, center(r).y);
  printf("Move: %d %d\n", move(r, 1, 1).upper_left.x,
         move(r, 1, 1).lower_right.y);
  printf("Contains: %d\n", contains(r, p));
  printf("Contains: %d\n", contains(r, p2));

  return 0;
}

// (a) Compute the area of r.
int area(struct rectangle r) {
  return (r.lower_right.x - r.upper_left.x) *
         (r.lower_right.y - r.upper_left.y);
}

// (b) Compute the center of r, returning it as a point value.
struct point center(struct rectangle r) {
  return (struct point){.x = (r.upper_left.x + r.lower_right.x) / 2,
                        .y = (r.upper_left.y + r.lower_right.y) / 2};
}

// (c) Move r by x units in the x direction and y units in the y direction,
//     returning the modified version of r.
struct rectangle move(struct rectangle r, int x, int y) {
  return (struct rectangle){
      .upper_left = {.x = r.upper_left.x + x, .y = r.upper_left.y + y},
      .lower_right = {.x = r.lower_right.x + x, .y = r.lower_right.y + y}};
}

// (d) Determine whether a point p lies within r, returning true or false.
bool contains(struct rectangle r, struct point p) {
  return p.x >= r.upper_left.x && p.x <= r.lower_right.x &&
         p.y >= r.upper_left.y && p.y <= r.lower_right.y;
}