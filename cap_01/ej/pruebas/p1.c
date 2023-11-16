#include "../ej_1_18.c"
#include <stdio.h>

int main() {
  //
  char frase[30] = "hola          \n";
  del_end_white(frase, 30);
  printf("%s", frase);
  return 0;
}
