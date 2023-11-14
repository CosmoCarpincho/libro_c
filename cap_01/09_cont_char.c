// cuenta los caracteres de entrada
#include <stdio.h>

int main() {
  double nc;

  // ; se le llama proposición nula
  for (nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n", nc);

  return 0;
}
