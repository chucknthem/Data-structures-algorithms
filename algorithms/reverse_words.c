#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Reverse the order of words in a string in place.
 *
 * 1. Reverse the string.
 * 2. Reverse each word in the string.
 */

void reverse(char* str, int i, int j) {
  char tmp;
  for (; i < j; i++, j--) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
  }
}

/* 
 * Find the end of a word from the start position
 */
int wordEnd(char* str, int start, int len) {
  int i = start;
  while (i < len) {
    if (!isalpha(str[i]) && !isdigit(str[i])) {
      return i - 1;
    }
    i++;
  }

  return start;
}

int main(int argc, char** argv) {
  char* str = argv[1];
  char* dup = strdup(str);
  int len = strlen(str);
  reverse(str, 0, len - 1);
  int start = 0;
  int end;
  while (start < len) {
    if (isalpha(str[start]) || isdigit(str[start])) {
      end = wordEnd(str, start, len);
      reverse(str, start, end);
      start = end;
    }

    start++;
  }

  printf("\"%s\" reversed is \"%s\"\n", dup, str);
  free(dup);
  return 0;
}

