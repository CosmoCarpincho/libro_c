/*Ejercicio 1-20. Escriba un programa detab que reemplace tabuladores de la en­
 * trada con el número apropiado de blancos para espaciar hasta el siguiente
 * paro de tabulación. Considere un conjunto fijo de paros de tabulación,
 * digamos cada n columnas. ¿Debe ser n una variable o un parámetro simbólico?*/

#include <stdio.h>
#define LEN_LINE 500
#define TAB_TO_SPACES 4

int getline_2(char s[], int length); // Retorna tam line o EOF cuando finaliza
void tab_to_spaces(char s[], int length);

// Retorna tam line o EOF cuando finaliza
int getline_2(char s[], int length) {

  int i, c;
  for (i = 0; i < length - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
    s[i++] = c; // Esta linea es muy hardcord.

  s[i] = '\0';

  return i;
}
void tab_to_spaces(char s[], int length) {

  char buff[length];
  int c;
  int i = 0, j = 0;
  for (; s[i] != '\0' && i < length - 1; ++i) {
    if (s[i] == '\t') {
      for (int k = 0; k < TAB_TO_SPACES; ++k)
        buff[j++] = ' ';
    } else {
      buff[j++] = s[i];
    }
  }

  buff[++j] = '\0';

  int m;
  for (m = 0; m < length - 1 && buff[m] != '\0'; ++m)
    s[m] = buff[m];

  s[m] = '\0';
}

int main() {
  /*
   */
  char line[LEN_LINE];
  char line_spaces[LEN_LINE];
  int tam_line;
  while ((tam_line = getline_2(line, LEN_LINE)) > 0) {
    tab_to_spaces(line, LEN_LINE);

    printf("%s", line);
  }
  return 0;
}
