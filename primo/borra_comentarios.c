#include <stdio.h>

void removeComments(FILE *inputFile, FILE *outputFile) {
  int c, next;

  while ((c = fgetc(inputFile)) != EOF) {
    if (c == '/') {
      next = fgetc(inputFile);

      // Comentario de línea
      if (next == '/') {
        while ((c = fgetc(inputFile)) != '\n' && c != EOF) {
        }
      }
      // Comentario de bloque
      else if (next == '*') {
        int prev = ' ';
        while ((c = fgetc(inputFile)) != EOF) {
          if (prev == '*' && c == '/')
            break;
          prev = c;
        }
      }
      // No es un comentario, escribir caracteres
      else {
        fputc(c, outputFile);
        fputc(next, outputFile);
      }
    }
    // No es un comentario, escribir el carácter
    else {
      fputc(c, outputFile);
    }
  }
}

int main() {
  FILE *inputFile, *outputFile;

  // Cambia "input.c" y "output.c" con los nombres de tus archivos de entrada y
  // salida
  inputFile = fopen("input.c", "r");
  if (inputFile == NULL) {
    perror("Error al abrir el archivo de entrada");
    return 1;
  }

  outputFile = fopen("output.c", "w");
  if (outputFile == NULL) {
    perror("Error al abrir el archivo de salida");
    fclose(inputFile);
    return 1;
  }

  removeComments(inputFile, outputFile);

  fclose(inputFile);
  fclose(outputFile);

  printf("Comentarios eliminados con éxito.\n");

  return 0;
}
