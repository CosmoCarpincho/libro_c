// yt afd
// https://www.youtube.com/watch?v=-G_g9aIcMPE
// Cadenas de longitud par iniciadas en a
// Alfabeto = {a, b}
// K = {q0, q1, q2, q3}
// s = q0
// F = {q2}
// Tabla transicion de estados
//    a  b
// q0 1  3
// q1 2  2
// q2 1  1
// q3 3  3
//
#include <stdio.h>

// diagrama de transición de estados (se agrega 1 para errores)
size_t estados[][3] = {{1, 3, 3}, {2, 2, 3}, {1, 1, 3}, {3, 3, 3}};

// conjunto de estados finales
size_t finales[] = {2};
size_t cant_finales = 1;

// Alfabeto
size_t simbolos[] = {'a', 'b'};
size_t cant_simbolos = 2;

int i;
char lexema[100];

int automata(void);

int main(int argc, char **args) {
  char c;
  while ((c = getc(stdin)) != EOF) {
    ungetc(c, stdin);
    i = 0;
    if (automata()) {
      printf("Cadena válida -> ");
      lexema[i++] = '\0';
      printf("%s\n", lexema);

    } else {
      printf("Cadena NO válida -> ");
      lexema[i++] = '\0';
      printf("%s\n", lexema);
    }
  }

  return 0;
}

size_t posicion_alfabeto(char c);
int es_final(size_t);

int automata(void) {
  size_t estado = 0;
  char c;
  while ((c = getc(stdin)) != '\n') {
    lexema[i++] = c;
    estado = estados[estado][posicion_alfabeto(c)];
  }

  return es_final(estado);
}

size_t posicion_alfabeto(char c) {
  size_t i;
  for (i = 0; i < cant_simbolos; i++) {
    if (simbolos[i] == c)
      return i;
  }
  return i;
}

int es_final(size_t estado) {
  size_t i;
  for (i = 0; i < cant_finales; i++) {
    if (estado == finales[i])
      return 1;
  }
  return 0;
}
