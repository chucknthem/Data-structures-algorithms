#include <stdio.h>
/**
 * This function implements the addition operation using only bit operators.
 */
int add(int a, int b) {
  int c = a & b;
  while (a != 0) {
    c = b & a;
    b = b ^ a;
    c = c << 1;
    a = c;
  }
  return b;
}

int main() {
  printf("%d\n", add(51, 152)); // 203
}
