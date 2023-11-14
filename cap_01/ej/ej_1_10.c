/* Escriba un programa que cpie su entrada a la salida, reemplazando cada
 * tabulación por \t, cada retroceso por \b y cada diagonal invertida por \\.*/

#include <stdio.h>

int main() {

  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");

    else if (c == '\b')
      printf("\\b");

    else if (c == '\\')
      printf("\\\\");

    else {
      putchar(c);
    }
  }

  return 0;
}
