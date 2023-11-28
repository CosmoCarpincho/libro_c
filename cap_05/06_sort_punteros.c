#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // máx # de lineas por ordenar

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// ordena líneas de entrada
int main() {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: entrada demasiado grande para ordenarla\n");
    return 1;
  }
}

#define MAXLEN 1000
int getline_2(char *, int);
char *alloc(int);

// readlines: lee líneas de entrada

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline_2(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; // elimina carácter nueva línea
      strcpy(p, line);      // ?? p = line .. se puede hacer?? si dejamos el \0?
      lineptr[nlines++] = p;
    }
  return nlines;
}

// writelines: escribe líneas de salida
void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

// writelines otra forma de escribirlo
void writelines_2(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

// qsort: ordena v[left]...v[right] en orden ascendente
void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right) // no hace nada si el arreglo contiene < 2 elementos
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

// swap: intercambia v[i] y v[j]
void swap_2(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
