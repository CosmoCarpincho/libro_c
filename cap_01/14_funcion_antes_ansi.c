// Forma antigua de escribir C. Antes de ANSI.

#include <stdio.h>

int power();
//power();
// En la declaración antigua los parametros que se omiten se ponen por defecto en int
// Por lo tanto si no se pone la firma o prototipo de funcion deberia de andar.

int main(void) {
	
	printf("2**6: %d\n", power(2,6));
	return 0;
}

power(base, n)
int base, n;
{
  int i, p;

  p = 1;
  for (i = 1; i <= n; ++i)
    p = p * base;

  return p;
}
