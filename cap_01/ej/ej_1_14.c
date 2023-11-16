/*Ejercicio 1-14. Escriba un programa que imprima el histograma de las frecuen­
 * cias con que se presentan diferentes caracteres leídos a la entrada.*/

// ascii 33  '!' al 126 '~' caracteres imprimibles. 94
#include <stdio.h>

#define CANT_CHAR ('~' - '!' + 1) // Ojo para sacar la cantidad sumar 1

int main() {

  int c;
  int arr_char[CANT_CHAR];
  int nl, nother, nwhite = 0;

  printf("%d\n", CANT_CHAR);

  for (int i = 0; i < CANT_CHAR; i++)
    arr_char[i] = 0; // Inicializamos en 0

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {

      if (c == '\n')
        ++nl;
      if (c == '\t' || c == ' ')
        ++nwhite;
      else
        ++nother;

    } else {
      ++arr_char[c - '!']; // '!' = 33
    }
  }

  for (int j = 0; j < CANT_CHAR; j++) {
    printf("%c :", j + '!');
    for (int k = 0; k < arr_char[j]; k++)
      printf("|");
    printf("\n");
  }

  return 0;
}
