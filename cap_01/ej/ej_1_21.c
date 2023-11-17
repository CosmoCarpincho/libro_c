/*Ejercicio 1-21. Escriba un programa entab que reemplace cadenas de blancos por
 * el mínimo número de tabuladores y blancos para obtener el mismo espaciado.
 * Considere los paros de tabulación de igual manera que para detab. Cuando un
 * tabulador o un simple espacio en blanco fuese suficiente para alcanzar un
 * paro de tabulación, ¿a cuál se le debe dar preferencia?*/
// Cosmo: quiero hacerlo pero sin usar un get_line custom
// Directamente procesando caracter a caracter. Para cambiar un poco el estilo.
// Podria crear un metodo que directamente imprima en stdin o
// podria manejarlo con buffer, ... xq los tabs siempre son menos caracteres que
// spaces

#include <stdio.h>

#define TAM_BUFF 5000
#define TAB_SPACES 2

int spaces_to_tabs(char s[], int length_buff);

int spaces_to_tabs(char s[], int length_buff) {

  char buff[length_buff];
  int cont = 0;
  int k = 0;
  for (int i = 0; i < length_buff - 1 && s[i] != '\0'; ++i) {
    if (s[i] == ' ') {
      for (int j = i; j < TAB_SPACES + i; ++j) {
        if (s[j] == ' ')
          cont++;
      }
    }

    if (cont == TAB_SPACES) {
      i = i + TAB_SPACES - 1;
      buff[k++] = '\t';
    } else
      buff[k++] = s[i];

    cont = 0;
  }
  buff[k] = '\0';

  int m;
  for (m = 0; buff[m] < length_buff - 1 && buff[m] != '\0'; ++m)
    s[m] = buff[m];

  s[m] = '\0';

  return m;
}
int main() {

  int c;
  char buff[TAM_BUFF];

  int i;
  for (i = 0; (c = getchar()) != EOF && i < (TAM_BUFF - 1); ++i) {
    buff[i] = c;
  }
  buff[i] = '\0';
  spaces_to_tabs(buff, TAM_BUFF);
  printf("%s", buff);

  return 0;
}
