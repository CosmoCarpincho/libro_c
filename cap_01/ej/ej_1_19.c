
/*Ejercicio 1-19. Escriba una función reverse(s) que invierta la cadena de
 * caracte­ res s. Usela para escribir un programa que invierta su entrada,
 * línea a línea.*/
// COSMO: se puede hacer mas eficiente. Si se hace un reverse que vaya cambiando
// posición final con inicial hasta la mitad te ahorras el buffer. Con una
// variable auxiliar nomas ya estaria.
#include <stdio.h>

#define LENGTH_TEXT 10000
#define TAM_LINEA 300

void reverse(char line[], unsigned int length);

void reverse(char line[], unsigned int length) {
  char buff[length];

  // OJOO!!! ESTO NO SIRVE. PORQUE PUEDE TENER DE
  // CÓDIGO BASURA \0. POR ESO ES IMPORTANTE QUE
  // PASEN BIEN EL LENGTH
  /*
  for (; length >= 0 && line[length] != '\0'; --length)
    ;
*/
  // LA UNICA FORMA DE PODER TRATAR BUFFERS MAS GRANDES QUE SU CONTENIDO ES:
  // RECORRERLO DESDE EL PRINCIPIO HASTA ENCONTRAR EL PRIMER \0

  int indice;
  for (indice = 0; indice < length && line[indice] != '\0'; ++indice)
    ;

  buff[indice] = '\0';
  --indice;

  if (indice == 0)
    return;

  if (line[indice] == '\n') {
    buff[indice] = line[indice];
    --indice;
  }

  int i;

  for (i = 0; i <= indice; ++i) {
    buff[i] = line[indice - i];
  }

  for (int j = 0; j <= indice; ++j) {
    line[j] = buff[j];
  }
}

int main() {

  int c;
  char linea[TAM_LINEA];
  int i;
  int j = 0;
  for (i = 0; i < LENGTH_TEXT - 1 && (c = getchar()) != EOF; ++i) {
    linea[j] = (char)c;

    if (c == '\n') {
      linea[j + 1] = '\0';
      reverse(linea, j);
      printf("%s", linea);
      j = 0;
    } else {
      ++j;
    }
  }

  return 0;
}
