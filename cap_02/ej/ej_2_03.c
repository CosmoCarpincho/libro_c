/*Ejercicio 2-3. Escriba la función htoi(s), que convierte una cadena de dígitos
 * hexadecimales (incluyendo Ox ó OX en form a optativa) en su valor entero
 * equiva­ lente. Los dígitos perm itidos son del 0 al 9, de la a a la f, y de
 * la A a la F.*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIG 100

int htoi(char s[]) {
  int buff[MAX_DIG];
  int decimal = 0;
  int j = 0;

  // recorrer hasta el primer x.
  int i;
  for (i = 0; s[i] != 'x' && s[i] != 'X' && s[i] != '\0'; ++i)
    ;

  if (s[i] == '\0') {

    printf("No ingreso un número o error en el formato. Usar 0xnn..\n");
    exit(1);
  }

  // Verifica el formato 0x
  if (s[i - 1] == '0') {
    i++;
    for (; s[i] != '\0' && s[i] != '\n'; ++i) {

      if (s[i] >= '0' && s[i] <= '9')
        buff[j++] = s[i] - '0';
      else if (s[i] >= 'A' && s[i] <= 'F')
        buff[j++] = s[i] - 'A' + 10;
      else if (s[i] >= 'a' && s[i] <= 'f')
        buff[j++] = s[i] - 'a' + 10;
      else {
        printf("Error no es un hexadecimal\n");
        exit(1);
      }
    }
    /*
    --j;
    double final = (double) j;
    // recorro el buff del digito menos significativo al mas significativo
    for (; j >= 0; --j) {
      decimal += pow(final - (double)j, 16.) + buff[j];
    }
    */
  }

  for (int i = 0; i < j; ++i)
    decimal = decimal * 16 + buff[i];

  return decimal;
}

int main() {
  int c;
  char buff[MAX_DIG + 1];
  int decimal;
  printf("Ingrese un número hexadecimal de hasta %d digitos:  ", MAX_DIG);
  for (int i = 0; ((c = getchar()) != EOF); ++i)
    buff[i] = c;

  decimal = htoi(buff);
  printf("en decimal es: %d\n", decimal);
  return 0;
}
