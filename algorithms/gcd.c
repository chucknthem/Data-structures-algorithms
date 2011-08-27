#include <stdio.h>

/*
 * Eulers algorithm for calculating the greatest common divisor of two numbers.
 *
 * gcd(a, b) is the largest number that divides both a and b. If that number is 1, then a and b
 * are co-prime.
 *
 * Euler discovered that gcd(a, b) = gcd(a - b, b) if a > b and gcd(a, b) = gcd(a, b - a) if b > a
 * Which gives us a very fast way of calculating the gcd without doing any prime factoring.
 */
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}

int main(void) {
  printf("gcd(%d, %d) = %d\n", 124, 1262, gcd(144, 122334));
  return 0;
}
