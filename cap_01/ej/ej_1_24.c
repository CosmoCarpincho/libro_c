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
#include <malloc.h>
#include <stdio.h>

#define FIN_STACK (-1)

struct nodo {
  char c;
  struct nodo *next;
};

struct nodo *create_nodo();
void push(struct nodo **pila, char caracter);
int pop(struct nodo **pila);
void is_empty(struct nodo *pila);

struct nodo *create_nodo() {
  struct nodo *n = malloc(sizeof(struct nodo));
  return n;
}

void push(struct nodo **pila, char caracter) {
  struct nodo *nodo = create_nodo();
  nodo->c = caracter;
  if (*pila == NULL)
    nodo->next = NULL;
  else
    nodo->next = *pila;

  *pila = nodo;
}

int pop(struct nodo **pila) {
  if (*pila == NULL)
    return FIN_STACK;
  int c;
  c = (*pila)->c;


  struct nodo *nodo;
  nodo = *pila;
  *pila = (*pila)->next;
  free(nodo);
  return c;
}

int main() {
  struct nodo *pila = NULL;

  for (int i = 0; i < 4; ++i)
    push(&pila, (char)(i + 'a'));

  int c;
  for (int j = 0; j < 4; ++j)

    if ((c = pop(&pila)) != FIN_STACK)
      printf("%c \n", (char)c);
    else
      printf("La pila esta vacia");

  /*
   */
  return 0;
}
