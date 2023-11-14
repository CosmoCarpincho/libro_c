#include <stdio.h>

/* imprime la tabla de Fahrenheit-Celsius para fahr = 0, 20, 30, ... 300 */

int main(void) {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9; // La division trunca el numero
                                   // por eso se hace al final
                                   // Parte fracionaria se descarta
    printf("%3d\t%6d\n", fahr, celsius);
    fahr = fahr + step;
  }
}
