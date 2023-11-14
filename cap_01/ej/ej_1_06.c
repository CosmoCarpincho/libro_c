#include <stdio.h>

int main() {

  int c;

  while (c = getchar() != EOF) { // c = 1. siempre.
    printf("Adentro %d\n", c);
    putchar(c);
  }

  return 0;
}
