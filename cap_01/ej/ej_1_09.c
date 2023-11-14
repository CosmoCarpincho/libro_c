/* Copie su entrada a la salida, reemlanzo cada cadena de uno o más blancos por
 * un solo blanco*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      state = IN;
    } else {
      if (state == IN) {
        putchar(' ');
        state = OUT;
      }
      putchar(c);
    }
  }
}
