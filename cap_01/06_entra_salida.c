#include <stdio.h>

int main() {
  int c; // se usa int para el EOF etc. xq este valor esta fuera del rango de
         // los caracteres

  c = getchar(); // te da el siguiente caracter de stdin

  while (c != EOF) { // EOF end of file. Final de línea.
    putchar(c);      // manda caracter a stdout
    c = getchar();
  }
}
