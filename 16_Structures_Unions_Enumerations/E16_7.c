// Exercise 16.7

/*

    Assume that the fraction structure contains two members: numerator and
   denomi- nator (both of type int). Write functions that perform the following
   operations on frac- tions:

    a) Reduce the fraction f to lowest terms. Hint: To reduce a fraction to
   lowest terms, first compute the greatest common divisor (GCD) of the
   numerator and denominator. Then divide both the numerator and denominator by
   the GCD.
   (b) Add the fractions f1 and f2.
   (c) Subtract the fraction f2 from
   the fraction f1.
   (d) Multiply the fractions f1 and f2. (e) Divide the
   fraction f1 by the fraction f2.

    The fractions f, f1, and f2 will be arguments of type struct fraction; each
   function will return a value of type struct fraction. The fractions returned
   by the functions in parts (b)–(e) should be reduced to lowest terms. Hint:
   You may use the function from part (a) to help write the functions in parts
   (b)–(e).
*/

#include <stdint.h>
#include <stdio.h>

uint64_t gcd(uint64_t, uint64_t);

struct fraction {
  int numerator;
  int denominator;
};

struct fraction reduce_fraction(struct fraction f);
struct fraction add_fraction(struct fraction f1, struct fraction f2);
struct fraction multiply_fraction(struct fraction f1, struct fraction f2);
struct fraction subtract_fraction(struct fraction f1, struct fraction f2);
struct fraction divide_fraction(struct fraction f1, struct fraction f2);

int main(void) {
  struct fraction f1 = {4, 5};
  struct fraction f2 = {2, 3};

  printf("f1 = %d/%d\n", f1.numerator, f1.denominator);
  printf("f2 = %d/%d\n", f2.numerator, f2.denominator);

  printf("f1 + f2 = %d/%d\n", add_fraction(f1, f2).numerator,
         add_fraction(f1, f2).denominator); // 4/5 + 2/3 = 12/15 + 10/15 = 22/15
  printf("f1 - f2 = %d/%d\n", subtract_fraction(f1, f2).numerator,
         subtract_fraction(f1, f2)
             .denominator); // 4/5 - 2/3 = 12/15 - 10/15 = 2/15
  printf("f1 * f2 = %d/%d\n", multiply_fraction(f1, f2).numerator,
         multiply_fraction(f1, f2).denominator); // 4/5 * 2/3 = 8/15
  printf("f1 / f2 = %d/%d\n", divide_fraction(f1, f2).numerator,
         divide_fraction(f1, f2)
             .denominator); // 4/5 / 2/3 = 4/5 * 3/2 = 12/10 = 6/5

  return 0;
}

struct fraction reduce_fraction(struct fraction f) {
  uint64_t numerator = f.numerator < 0 ? (uint64_t)(-(f.numerator + 1)) + 1
                                       : (uint64_t)f.numerator;
  uint64_t denominator = f.denominator < 0
                             ? (uint64_t)(-(f.denominator + 1)) + 1
                             : (uint64_t)f.denominator;

  int common = gcd(numerator, denominator);

  return (struct fraction){.numerator = f.numerator / common,
                           .denominator = f.denominator / common};
}

struct fraction add_fraction(struct fraction f1, struct fraction f2) {
  return reduce_fraction(
      (struct fraction){.numerator = f1.numerator * f2.denominator +
                                     f2.numerator * f1.denominator,
                        .denominator = f1.denominator * f2.denominator});
}

struct fraction multiply_fraction(struct fraction f1, struct fraction f2) {
  return reduce_fraction(
      (struct fraction){.numerator = f1.numerator * f2.numerator,
                        .denominator = f1.denominator * f2.denominator});
}

struct fraction subtract_fraction(struct fraction f1, struct fraction f2) {
  return add_fraction(f1, (struct fraction){.numerator = -f2.numerator,
                                            .denominator = f2.denominator});
}

struct fraction divide_fraction(struct fraction f1, struct fraction f2) {
  return multiply_fraction(f1, (struct fraction){.numerator = f2.denominator,
                                                 .denominator = f2.numerator});
}

// Cross-platform trailing zero count for maximum performance
static inline int fast_ctz64(uint64_t n) {
#if defined(_MSC_VER)
  unsigned long index;
  _BitScanForward64(&index, n);
  return (int)index;
#else
  return __builtin_ctzll(n);
#endif
}

uint64_t gcd(uint64_t a, uint64_t b) {
  // Handle edge cases
  if (a == 0)
    return b;
  if (b == 0)
    return a;

  // Factor out common powers of 2: gcd(2^k * a, 2^k * b) = 2^k * gcd(a, b)
  int shift = fast_ctz64(a | b);

  // Remove all factors of 2 from a (since it must be odd for the loop)
  a >>= fast_ctz64(a);

  do {
    // Remove all factors of 2 from b (it is now even or odd)
    b >>= fast_ctz64(b);

    // Ensure a <= b
    if (a > b) {
      uint64_t temp = a;
      a = b;
      b = temp;
    }

    // Since both a and b are odd, b - a is even
    b -= a;
  } while (b != 0);

  // Restore the common powers of 2
  return a << shift;
}