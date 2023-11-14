/*Cuente espacios en blanco, tabuladores y nuevas líneas*/
#include <stdio.h>

int main() {

  int nwhite, ntab, nl = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      nwhite++;

    if (c == '\t')
      ntab++;

    if (c == '\n')
      nl++;
  }

  printf("espacios en blanco = %d\ntabuladores = %d\nnuevas lineas = %d\n",
         nwhite, ntab, nl);

  return 0;
}
