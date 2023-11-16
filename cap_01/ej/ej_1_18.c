// COSMO: TODO: MEJORAR CÓDIGO
// Esta mal la lógica de eliminar lineas en blanco
/*Ejercicio 1-18. Escriba un programa que elimine los blancos y los tabuladores
 * que estén al final de cada línea de entrada, y que borre completamente las
 * líneas en blanco.*/

#include <stdio.h>

#define MAX_LINE 500
#define WHITE (-1)

int del_end_white(char line[], int length);
void del_line_white(char line[], int length);
int get_line(char s[], int max_line);

int main() {

  char buffer[MAX_LINE];
  int len_line;

  while ((len_line = get_line(buffer, MAX_LINE)) != EOF) {
    // del_line_white(buffer, len_line);
    len_line =
        del_end_white(buffer, len_line); // si no tiene nada mas que lineas en
                                         // blanco va a borrar todo.
    if (len_line != WHITE)
      printf("%s", buffer);
  }
  return 0;
}

int del_end_white(char line[], int length) {
  // Si no te dan bien el tamaño. Busca el final
  int j;
  int fin;
  for (j = length; j >= 0 && line[j] != '\0'; --j)
    ;
  if (line[j] == '\0')
    fin = j;
  else
    return WHITE;

  if (line[j - 1] == '\n')
    --fin;

  int i;
  for (i = fin - 1; i >= 0; --i) {
    if (line[i] == '\t' || line[i] == ' ')
      line[i] = '\0';
    else
      break;
  }
  i++;
  line[i] = '\n';
  i++;
  line[i] = '\0';

  return i + 1;
}

/*
void del_line_white(char line[], int length) {
  int contenido = 0;
  for (int i = 0; i < length; i++)
    ;
}
*/

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

  if (c == EOF)
    i = c;

  s[i] = '\0';

  return i;
}
