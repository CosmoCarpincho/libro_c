/*Ejercicio 2-2. Escriba un ciclo equivalente a la iteración for anterior sin
 * usar && o ||*/

#include <stdio.h>
#define LIM 10

int main() {
  int lim = LIM;
  char s[LIM];
  int c;

  // ciclo original
//  for (int i = 0; lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 //   s[i] = c;

  // ciclo sin && o ||

    for (int j = 0; (j < (lim - 1)) * ((c = getchar()) != '\n') * (c != EOF);
    ++j)
     s[j] = c;

  s[9] = '\0';

  printf("%s", s);

  return 0;
}
