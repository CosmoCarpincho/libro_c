#include <stdio.h>

int main(void) {

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  while (fahr <= upper) {

    // el 32 se convierte a float pero para ser mas visual
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);

    fahr = fahr + step;
  }

  return 0;
}
