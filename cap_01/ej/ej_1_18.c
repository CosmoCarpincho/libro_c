/*Ejercicio 1-18. Escriba un programa que elimine los blancos y los tabuladores
 * que estén al final de cada línea de entrada, y que borre completamente las
 * líneas en blanco.*/

#include <stdio.h>

#define MAX_LINE 500
#define WHITE (-1)

int del_end_white(char line[], int length);
int del_line_white(char line[], int length);
int get_line(char s[], int max_line);

int main() {

  char buffer[MAX_LINE];
  int len_line;

  while ((len_line = get_line(buffer, MAX_LINE)) > 0) {

    len_line = del_end_white(buffer, len_line);
    // printf("%d ", len_line);
    len_line = del_line_white(buffer, len_line);
    // printf("%d\n", len_line);

    printf("%s", buffer);
  }
  return 0;
}

int del_end_white(char line[], int length) {
  // Si no te dan bien el tamaño. Busca el final
  int fin;
  int puntero = 0;

  // Esto no sirve explicado en 1.19. Te tienen que pasar el length bien.
  for (fin = length; fin >= 0 && line[fin] != '\0'; --fin)
    ;

  if (line[fin] != '\0') {
    line[0] = '\0';
    return 0;
  }

  if (line[fin - 1] == '\n')
    puntero = fin - 2;
  else
    puntero = fin - 1;

  for (; puntero >= 0; --puntero) {
    if (line[puntero] == '\t' || line[puntero] == ' ')
      line[puntero] = '\0';
    else
      break;
  }
  puntero++;
  line[puntero] = '\n';
  puntero++;
  line[puntero] = '\0';

  return puntero + 1;
}
int del_line_white(char line[], int length) {
  int i;
  for (i = 0; i < length && line[i] != '\0' &&
              (line[i] == ' ' || line[i] == '\t' || line[i] == '\n');
       i++)
    ;
  if ((line[i] == '\0' && i == 0) || (line[i] == '\0' && line[i - 1] == '\n')) {
    line[0] = '\0';
    length = 0;
  }

  return length;
}

int get_line(char s[], int max_line) {
  int c;
  int i;
  for (i = 0; (i < max_line - 1) && ((c = getchar()) != EOF) && (c != '\n');
       ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = '\n';
    i++;
  }
  s[i] = '\0';

  return i;
}
