#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

#define CELSIUS_TO_FAHR(x) ((5.0 / 9.0) * (x - 32))

int main() {

  for (int fahr = 0; fahr <= UPPER; fahr += STEP)
    printf("%6d %6.2f\n", fahr, CELSIUS_TO_FAHR(fahr));

  return 0;
}
