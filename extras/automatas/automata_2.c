// lexer.c
// de yt
// https://www.youtube.com/watch?v=CnBkVsL0iko
//
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define ENTERO 0
#define FLOTANTE 1
#define ERROR 3
#define ESPACIO 4
#define FIN 5

typedef struct token {
  char lexema[100];
  int tipo;
} token_t;

// + - . digito espacio otro
size_t estados[][6] = {
    {1, 1, 3, 2, 7, 8}, {8, 8, 3, 2, 8, 8}, {5, 5, 3, 2, 5, 5},
    {8, 8, 8, 4, 8, 8}, {6, 6, 6, 4, 6, 6}, {8, 8, 8, 8, 8, 8},
    {8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8}, {8, 8, 8, 8, 8, 8}};

size_t simbolos[] = {'+', '-', '.'};
size_t cant_simbolos = 3;

token_t automata(void);
char *tipo(token_t);

int main(int argc, char **args) {
  token_t t;
  while ((t = automata()).tipo != FIN) {
    if (t.tipo != ESPACIO)
      printf("%s - %s\n", t.lexema, tipo(t));
  }

  return 0;
}

size_t posicion_alfabeto(char);
int es_final(size_t);

token_t automata(void) {
  token_t t;
  size_t estado = 0;
  char c;
  size_t i = 0;
  while ((c = getc(stdin)) != EOF) {
    t.lexema[i++] = c;
    estado = estados[estado][posicion_alfabeto(c)];
    // Estados trigger (estados de acción)
    switch (estado) {
    case 5:
      ungetc(c, stdin);
      t.lexema[i - 1] = '\0';
      t.tipo = ENTERO;
      return t;
    case 6:
      ungetc(c, stdin);
      t.lexema[i - 1] = '\0';
      t.tipo = FLOTANTE;
      return t;
    case 7:
      t.lexema[i - 1] = '_';
      t.lexema[i] = '\0';
      t.tipo = ESPACIO;
      return t;
    case 8:
      t.lexema[i] = '\0';
      t.tipo = ERROR;
      return t;
    }
  }
  t.tipo = FIN;
  t.lexema[0] = '\0';
  return t;
}

size_t posicion_alfabeto(char c) {
  size_t i;
  for (i = 0; i < cant_simbolos; i++)
    if (simbolos[i] == c)
      return i;

  if (isdigit(c))
    return i;

  if (isspace(c))
    return i + 1;
  return i + 2;
}

char *tipo(token_t t) {
  char *tipo = calloc(13, sizeof(char));
  switch (t.tipo) {
  case ENTERO:
    strcpy(tipo, "entero");
    break;
  case FLOTANTE:
    strcpy(tipo, "flotante");
    break;
  case ERROR:
    strcpy(tipo, "error");
    break;
  case ESPACIO:
    strcpy(tipo, "espacio");
    break;
  case FIN:
    strcpy(tipo, "fin");
    break;
  default:
    strcpy(tipo, "desconocido");
    break;
  }

  return tipo;
}
