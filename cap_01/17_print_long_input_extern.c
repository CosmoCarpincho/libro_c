// Misma funcionalidad que línea más larga pero con variables externas. (1.10)

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline_2(void);
void copy(void);

int main() {

  int len;
  // el extern es opcional porque esta todo en el mismo archivo
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline_2()) > 0)
    if (len > max) {
      max = len;
      copy();
    }

  if (max > 0)
    printf("%s", longest);

  return 0;
}

int getline_2(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
