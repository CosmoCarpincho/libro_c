// Escribir programa que imprima el valor de EOF.
#include <math.h>
#include <stdio.h>

int main() {

  int a;
  printf("tam en bytes de tipo int: %lu\n", sizeof(a));

  int num_bits_int = sizeof(a) * 8;
  double aux;

  // Se divide porque el rango va de negativos a positivos
  for (int j = 0; j < (num_bits_int / 2.0); j++)
    aux += pow(2, j);

  int max_number_int = (int)aux - 1;
  int min_number_int = (int)-aux;
  printf("Numero minimo int: %d,  Número maximo: %d\n", min_number_int,
         max_number_int);

  int valor_eof;
  for (int k = min_number_int; k <= max_number_int; k++) {
    if (k == EOF) {
      printf("EOF = ");
      valor_eof = k;
    }
    printf("%d ", k);
  }

  printf("\nEl valor de EOF es: %d\n", valor_eof);

  return 0;
}
