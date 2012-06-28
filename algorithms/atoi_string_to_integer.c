#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char** argv) {
  char* str = argv[1];
  int sum = 0;
  int len = strlen(str); 
  int i;
  for (i = 0; i < len; i++) {
    assert(str[i] >= '0' && str[i] <= '9');
    sum = sum * 10 + str[i] - '0';
  }

  printf("%d\n", sum);
  return 0;
}
