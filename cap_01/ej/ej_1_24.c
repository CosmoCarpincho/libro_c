/* Cosmo: ERROR. TENGO QUE REHACER EL EJERCICIO.
Me frene porque el diseño del automata esta mal. Necesito agregar 1 estado mas desde q2 para [ ].
Ademas de q2 q3 q4 q5 q6 q7 se deberia poder entrar en q8 pero para recordar el orden se multiplicarian los
estados.
Creo que una forma de entrar en q8 y no tener que crear muchos estados es agregar simbolos
al alfabeto de la pila. Por ejemplo un simbolo por estado.
Entonces al entrar al q8 apilas el simbolo del estado y sirve para redireccionar la vuelta. 
Consiguiendo una forma de entrar y salir de q8 de forma ordenada,

Otro problema es como hacer para reducir el código. Quise armar funciones para que quede mas prolijo pero igual
no me gusta. Si dejo todo dentro de una función queda con muchos if o swtch.
Si utilizo una matriz voy a tener que crear punteros a funcines y creo que es peor.

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
#include <string.h>

#define FIN_STACK (-1)
#define TAM_ALFABETO

#define  SIN_ERROR 0
#define ERROR_CERRAR_SIMBOLO 1
#define ERROR_CARACTER_INCORRECTO 2
#define ERROR_SALTO_LINEA 3

// variables y estructuras globales
enum states { q1 = 1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12 };
struct nodo *pila = NULL;

struct nodo {
  char c;
  int nline;
  struct nodo *next;
};

struct error {
  int n_error;
  char msg_error[500];
};

// declaraciones funciones
struct nodo *create_nodo();
void push(struct nodo **pila, char caracter, int n_line);
int pop(struct nodo **pila, int *n_line);
// void is_empty(struct nodo *pila);
void error_automata();
int automata(int c, int n_line, struct error * error);
void set_error(struct error * error, int n_error, int n_linea, char c);
char * error_string(int *n_error);


// definiciones de funciones
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
  if (n_line != NULL)
    *n_line = (*pila)->nline;

  struct nodo *nodo;
  nodo = *pila;
  *pila = (*pila)->next;
  free(nodo);
  return c;
}

char * error_string(int *n_error){
  char msg_error [300]= "";
  switch (*n_error)
  {
  case SIN_ERROR:
    /* code */
    break;
  case ERROR_CERRAR_SIMBOLO:
    strcpy(msg_error, "Falta %c que cierre. Error linea %n.\n");
    
    break;
  case ERROR_CARACTER_INCORRECTO:
    break;
  case ERROR_SALTO_LINEA:
  break;
  default:
    break;
  }

  return "hola";
}

void set_error(struct error * error, int n_error, int n_linea, char c){
  char msg_error[500];
  switch (n_error)
  {
  case SIN_ERROR:
    /* code */
    break;
  case ERROR_CERRAR_SIMBOLO:
  sprintf(msg_error, "Error linea: %n - EL simbolo %c no cerro correctamente. \n", n_linea, c);
  strcpy(error->msg_error, msg_error);

    break;
  case ERROR_CARACTER_INCORRECTO:
  sprintf(msg_error, "Linea %n - El caracter %c es incorrecto.\n", n_linea);
  strcpy(error->msg_error, msg_error);
    break;
  case ERROR_SALTO_LINEA:
  break;
  default:
    break;
  }

}

enum states f_q1(int c, int n_line, struct error * error);
enum states f_q2(int c, int n_line, struct error * error);
enum states f_q3(int c, int n_line, struct error * error);
enum states f_q4(int c, int n_line, struct error * error);
enum states f_q5(int c, int n_line, struct error * error);
enum states f_q6(int c, int n_line, struct error * error);
enum states f_q7(int c, int n_line, struct error * error);
enum states f_q8(int c, int n_line, struct error * error);
enum states f_q9(int c, int n_line, struct error * error);
enum states f_q10(int c, int n_line, struct error * error);
enum states f_q11(int c, int n_line, struct error * error);
enum states f_q12(int c, int n_line, struct error * error);

enum states f_q1(int c, int n_line, struct error * error) {
  enum states state;
  switch (c) {
  case '{':
    state = q2;
    break;
  case '}':
    state = q1;
    break;
  case '(':
    state = q5;
    break;
  case ')':
    state = q1;
    break;
  case '[':
    state = q7;
    break;
  case ']':
    state = q1;
    break;
  case '"':
    state = q8;
    break;
  case '\'':
    state = q10;
    break;
  case '\n':
    state = q1;
    break;
  default: // other
    state = q1;
    break;
  }
  error->n_error = SIN_ERROR;
  return state;
}

enum states f_q2(int c, int n_line, struct error * error) {
  enum states state;
  int n_linea_error;
  int c_pop;
  switch (c) {
  case '{':
    push(&pila, c, n_line);
    state = q2;
    break;
  case '}':
    if ((c_pop = pop(&pila, &n_linea_error)) == FIN_STACK)
      state = q1;
    else if ( c_pop == '}')
      state = q2;
    else {
      push(&pila, c_pop, n_linea_error); // volver a poner
      set_error(error, ERROR_CERRAR_SIMBOLO, n_linea_error, c);
    }
    break;
  case '(':
    state = q3;
    break;
  case ')':
    set_error(error, ERROR_CARACTER_INCORRECTO, n_line, c);
    state = q2;
    break;
  case '[': // me falta crear estados
    state = q7;
    break;
  case ']':
    state = q1;
    break;
  case '"':
    state = q8;
    break;
  case '\'':
    state = q10;
    break;
  case '\n':
    state = q1;
    break;
  default: // other
    state = q1;
    break;
  }
  error->n_error = SIN_ERROR;
  return state;
}
// Retorna nro de errores. 0 si no hay errores de sintaxis
int automata(int c, int n_line, struct error * error) {

  enum states state;
  state = q1;

  switch (state) {
  case q1:
    state = f_q1(c, n_line, error);
    break;
  case q2:
    state = f_q2(c, n_line, error);
    break;
  case q3:
    state = f_q3(c, n_line, error);
    break;
  case q4:
    state = f_q4(c, n_line, error);
    break;
  case q5:
    state = f_q5(c, n_line, error);
    break;
  case q6:
    state = f_q6(c, n_line, error);
    break;
  case q7:
    state = f_q7(c, n_line, error);
    break;
  case q8:
    state = f_q8(c, n_line, error);
    break;
  case q9:
    state = f_q9(c, n_line, error);
    break;
  case q10:
    state = f_q10(c, n_line, error);
    break;
  case q11:
    state = f_q11(c, n_line, error);
    break;
  case q12:
    state = f_q12(c, n_line, error);
    break;
  }
}

int main() {
/*  struct nodo *pila = NULL;

  for (int i = 0; i < 4; ++i)
    push(&pila, (char)(i + 'a'), 0);

  int c;
  for (int j = 0; j < 4; ++j)

    if ((c = pop(&pila, NULL)) != FIN_STACK)
      printf("%c \n", (char)c);
    else
      printf("La pila esta vacia");
*/

  struct error *p_error;

  // Recorrer texto de entrada y contar lineas
  int k;
  int c1;
  int number_line = 0;
  for (k = 0; (c1 = getchar()) != EOF; ++k) {
    if (c1 == '\n')
      number_line++;
    // ver pos c1
    // cambiar estado y apilar

    if (automata(c1, number_line, p_error) > 0)
    fprintf(stderr, error_string(p_error->msg_error));
  }
  return 0;
}
