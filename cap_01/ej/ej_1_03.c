/*Ejercicio 1-3. Modifique el programa de conversión de temperaturas de modo que
 * escriba un encabezado sobre la tabla.*/
#include <stdio.h>

int main(void) {

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("fahrenheit  celsius\n");

  while (fahr <= upper) {

    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%10.0f  %7.2f\n", fahr, celsius);

    fahr = fahr + step;
  }

  return 0;
}
