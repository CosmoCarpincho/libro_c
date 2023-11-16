/*Ejercicio 1-33. Escriba un programa que imprima el histograma de las
 * longitudes de las palabras de su entrada. Es fácil dibujar el histograma con
 * las barras hori­ zontales; la Orientación vertical es un reto más
 * interesante.*/
// TODO: Para mejorar el programa se podria quitar las palabras repetidas.

#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, ncw;
  int state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {

      if (state == IN) {
        putchar(' ');
        for (int i = 0; i < ncw; i++)
          putchar('|');

        putchar('\n');
        state = OUT;
      }

    } else {
      if (state == OUT)
        ncw = 1;
      else
        ncw++;

      putchar(c);
      state = IN;
    }
  }

  return 0;
}
