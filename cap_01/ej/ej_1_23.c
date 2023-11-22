// Cosmo: Terminar
/*Ejercicio 1-23. Escriba un programa para eliminar todos los comentarios de un
 * programa en C. No olvide manejar apropiadamente las cadenas entre comillas y
 * las constantes de carácter. Los comentarios de C no se anidan.*/

// Lo voy a hacer con algo parecido a un automata finito discreto
// Alfabeto = {\n. ", ', /, *, c = caracteres}
//     /  *  "  ' \n  c
// q0  1  0  6  7  0  0
// q1  2  3  6  7  0  0
// q2  2  2  2  2  8  2
// q3  3  4  3  3  3  3
// q4  5  4  3  3  3  3
// q5  1  0  6  7  0  0
// q6  6  6  0  6  6  6
// q7  7  7  7  0  7  7
// q8  1  0  6  7  0  0
// F = {q5, q8}

#include <ctype.h>
#include <malloc.h>
#include <stdio.h>

#define BUFF_SIZE_INIT 100
#define IS_ANOTHER_SYMBOL -1 // cuando es otro caracter

int states[][6] = {{1, 0, 6, 7, 0, 0}, {2, 3, 6, 7, 0, 0}, {2, 2, 2, 2, 8, 2},
                   {3, 4, 3, 3, 3, 3}, {5, 4, 3, 3, 3, 3}, {1, 0, 6, 7, 0, 0},
                   {6, 6, 0, 6, 6, 6}, {7, 7, 7, 0, 7, 7}, {1, 0, 6, 7, 0, 0}};

char simbolos[] = {'/', '*', '"', '\'', '\n'};
int cant_simbolos = 5;

int posicion_alfabeto(char c) {
  int i;
  for (i = 0; i < cant_simbolos; i++)
    if (simbolos[i] == c)
      return i;

  return IS_ANOTHER_SYMBOL;
}

int main() {
  int count = 0;
  int buffer_size = BUFF_SIZE_INIT;
  char *buffer = (char *)malloc(buffer_size * sizeof(char));
  char *buffer_final = (char *)malloc(buffer_size * sizeof(char));

  int c;
  while ((c = getchar()) != EOF) {
    buffer[count++] = (char)c;

    if (count == buffer_size) {
      buffer_size *= 2;
      buffer = (char *)realloc(buffer, buffer_size * sizeof(char));
      buffer_final = (char *)realloc(buffer_final, buffer_size * sizeof(char));

      if (buffer == NULL) {
        fprintf(stderr, "Error al asignar memoria. \n");
        return 1;
      }
    }
  }

  buffer[count] = '\0';
  int state = 0;
  int pos = 0;

  // Automata
  int comienza_guardar = 0;
  int i_primero_borrar;
  int i_ultimo_borrar;
  int j = 0;

  for (int i = 0; i < buffer_size && buffer[i] != '\0'; ++i) {
    if ((pos = posicion_alfabeto(buffer[i])) == IS_ANOTHER_SYMBOL)
      pos = 5;

    state = states[state][pos];
    buffer_final[j++] = buffer[i];
    // Se borra desde q1 -> q8, q1 -> q5 y ver que pasa con q1 -> q2 si no hay
    // mas caracteres y no hay \n al final
    if (state == 1 && comienza_guardar == 0)
      i_primero_borrar = i;

    if (state == 5 || state == 8) {
      j = i_primero_borrar;
    }
  }
  buffer_final[j] = '\0';

  printf("%s", buffer_final);

  free(buffer);
  free(buffer_final);

  return 0;
}
