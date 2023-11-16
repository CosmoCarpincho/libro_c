// Como las funciones en c reciben el argumento por valor
// se modifica power quitando la i

#include <stdio.h>

int power(int m, int n);

int main() {

  int i;

  for (i = 0; i < 10; ++i)
    printf("%d %d %d\n", i, power(2, i), power(-3, i));

  return 0;
}

int power(int base, int n) {
  int p;

  p = 1;
  for (p = 1; n > 0; --n)
    p = p * base;

  return p;
}
