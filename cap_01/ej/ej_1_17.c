/*Ejercicio 1-17. Escriba un programa que imprima todas las líneas de entrada
 * que sean mayores de 80 caracteres.*/

#include <stdio.h>
#define MAX_LINE 10000
#define LIMITE 80

int getlinea(char buff[], int max_line);

int main() {

  char c;
  char buff[MAX_LINE];
  int len;

  while ((len = getlinea(buff, MAX_LINE)) != EOF)
    if (len >= LIMITE)
      printf("%d -> %s\n", len, buff);

  return 0;
}

int getlinea(char buff[], int max_line) {
  int i, c;

  for (i = 0; (i < max_line - 1) && (c = getchar()) != EOF && (c != '\n');
       i++) {
    buff[i] = c;
  }

  i++;
  buff[i] = '\0';

  if (c == EOF)
    i = c;

  return i;
}
