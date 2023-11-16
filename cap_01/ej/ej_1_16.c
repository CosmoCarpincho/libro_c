/*Ejercicio 1-16. Corrija la rutina principal del programa de la línea más larga
 * de modo que imprima correctamente la longitud de líneas de entrada
 * arbitrariamente largas, y tanto texto como sea posible.*/

#include <stdio.h>
#define MAXLINE 1000

int getline_2(char line[], int maxline);
void copy(char to[], char from[]);

/* imprime la línea de entrada más larga */
int main() {
  int len; // long actual línea
  int max;
  char line[MAXLINE];    // líne a de entrada actual
  char longest[MAXLINE]; // línea mas larga

  max = 0;
  while ((len = getline_2(line, MAXLINE)) > 0) {
    printf("longitud: %d -> %s\n", len, line);
  }

  return 0;
}

/*lee una linea en s, regresa su longitud*/
int getline_2(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/*cpia 'from' en 'to', supone que to es suficientemente grande*/
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
