/*Ejercicio 1-15. Escriba de nuevo el programa de conversión de temperatura de
 * la sección 1.2, de modo que utilice una función para la conversión.*/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celsius(float fahr);

int main() {

  for (int fahr = LOWER; fahr < UPPER; fahr += STEP)
    printf("%d\t%.1f\n", fahr, fahr_to_celsius((float)fahr));

  return 0;
}

float fahr_to_celsius(float fahr) { return (5.0 / 9.0) * (fahr - 32); }
