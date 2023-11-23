/*
 * Ejercicio 1-24. Escriba un programa para revisar los errores de sintaxis
 * rudimentarios de un programa en C, como paréntesis, llaves y corchetes no
 * alineados. No olvide las comillas ni los apóstrofos, las secuencias de escape
 * y los comentarios. (Este programa es difícil si se hace completamente
 * general.)
 * */
// Para resolver este problema creo que lo mejor es hacer un automata de pila
// PILA:
// apilar()
// desapilar()
// tamaño_pila

// Alfabeto
// { } ( ) [ ] " ' \

#include <malloc.h>
#include <stdio.h>

#define FIN_STACK (-1)
#define TAM_ALFABETO 

struct nodo {
  char c;
  int nline;
  struct nodo *next;
};

struct nodo *create_nodo();
void push(struct nodo **pila, char caracter, int n_line);
int pop(struct nodo **pila, int *n_line);
//void is_empty(struct nodo *pila);

struct nodo *create_nodo() {
  struct nodo *n = malloc(sizeof(struct nodo));
  return n;
}

void push(struct nodo **pila, char caracter, int n_line) {
  struct nodo *nodo = create_nodo();
  nodo->c = caracter;
  nodo->nline = n_line;
  if (*pila == NULL)
    nodo->next = NULL;
  else
    nodo->next = *pila;

  *pila = nodo;
}

int pop(struct nodo **pila, int *n_line) {
  if (*pila == NULL)
    return FIN_STACK;
  int c;
  c = (*pila)->c;
  if(n_line != NULL)
    *n_line = (*pila)->nline;

  struct nodo *nodo;
  nodo = *pila;
  *pila = (*pila)->next;
  free(nodo);
  return c;
}

int main() {
  struct nodo *pila = NULL;

  for (int i = 0; i < 4; ++i)
    push(&pila, (char)(i + 'a'), 0);

  int c;
  for (int j = 0; j < 4; ++j)

    if ((c = pop(&pila, NULL)) != FIN_STACK)
      printf("%c \n", (char)c);
    else
      printf("La pila esta vacia");

  /*
   */

  // Recorrer texto de entrada y contar lineas
  int k;
  int c1;
  int number_line = 0;
  for (k = 0; (c1 = getchar()) != EOF; ++k){
    if (c1 == '\n')
      number_line++;
    // ver pos c1
    // cambiar estado y apilar

  }
  return 0;
}
