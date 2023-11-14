/*Ejercicio 1-4. Escriba un programa que imprima la tabla correspondiente
 * Celsius a Fahrenheit*/
#include <stdio.h>

int main(void) {

  float celsius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("celsius  fahrenheit\n");
  while (celsius <= upper) {

    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%7.0f  %10.2f\n", celsius, fahr);

    celsius = celsius + step;
  }

  return 0;
}
