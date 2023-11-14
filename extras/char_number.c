#include <limits.h>
#include <stdio.h>

int main() {
  printf("%d\n", CHAR_MAX);
  printf("%d\n", CHAR_MIN);

  for (int i = 0; i < 255; i++) {
    printf("%d => %c  ", i, i);
    if ((i % 6) == 0) {
      printf("\n");
    }
  }

  return 0;
}
