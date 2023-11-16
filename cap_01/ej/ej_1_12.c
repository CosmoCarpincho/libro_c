/*Ejercicio 1-12. Escriba un program a que im prima su entrada una palabra por
 * línea.*/

#include <stdio.h>

#define IN_WHITE 1
#define OUT_WHITE 0

int main() {

  int c;
  int state = OUT_WHITE;

  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t') {
      putchar(c);
      state = OUT_WHITE;
    } else {
      if (state == OUT_WHITE)
        putchar('\n');

      state = IN_WHITE;
    }
  }

  return 0;
}
