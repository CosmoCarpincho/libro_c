#include <stdio.h>

int main() {

  int arr[4];

  int i;
  for (i = 0; i < 4; ++i)
    arr[i] = i;

  i = 0;
  // mi suposición es que queda:
  // arr[0] = 9, arr[1]= 10, arr[2] = 2, arr[3] = 11;
  arr[i++] = 9;
  arr[i++] = 10;
  arr[++i] = 11;

  return 0;
}
