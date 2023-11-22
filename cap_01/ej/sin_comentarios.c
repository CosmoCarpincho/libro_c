 


#include <ctype.h>
#include <malloc.h>
#include <stdio.h>

#define BUFF_SIZE_INIT 10000
#define IS_ANOTHER_SYMBOL -1 
int states[][6] = {{1, 0, 6, 7, 0, 0}, {2, 3, 6, 7, 0, 0}, {2, 2, 2, 2, 8, 2},
                   {3, 4, 3, 3, 3, 3}, {5, 4, 3, 3, 3, 3}, {1, 0, 6, 7, 8, 0},
                   {6, 6, 0, 6, 6, 6}, {7, 7, 7, 0, 7, 7}, {1, 0, 6, 7, 0, 0}};

char simbolos[] = {'/', '*', '"', '\'', '\n'}; //'
int cant_simbolos = 5;

int posicion_alfabeto(char c) {
  int i;
  for (i = 0; i < cant_simbolos; i++)
    if (simbolos[i] == c)
      return i;

  return IS_ANOTHER_SYMBOL;
}

int main() {
  char *p1, *p2;
  char aux;
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

    int comienza_guardar = 0;
  int i_primero_borrar;
  int i_ultimo_borrar;
  int j = 0;

  for (int i = 0; i < buffer_size && buffer[i] != '\0'; ++i) {
    if ((pos = posicion_alfabeto(buffer[i])) == IS_ANOTHER_SYMBOL)
      pos = 5;

    state = states[state][pos];

    aux = buffer[i - 2];
            
        if (state == 7 && buffer[i] == '\'' && buffer[i - 1] == '\\') { //'
      state == 7;

      if (aux == '\\')
        state == 0;

    }

    buffer_final[j++] = buffer[i];

            if (state == 1 && comienza_guardar == 0) {
      i_primero_borrar = --j;
      comienza_guardar = 1;
    }

    if (state == 5 || state == 8) {
      j = i_primero_borrar;
      comienza_guardar = 0;
    }
  }
  buffer_final[j] = '\0';

  printf("%s", buffer_final);

  free(buffer);
  free(buffer_final);

  return 0;
}
