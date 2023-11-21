// Acepta cadenas que contienen un número par de ceros y un número par de unos.
// K = {q0, q1, q2, q3, q4, q5}
// Sigma = { 0, 1}
// s = Q0
// delta = ((Q0,0),)...
// F = {}

#include <stdio.h>

#define TAM_BUFF 1000

typedef enum {
  q0, // Estado inicial
  q1,
  q2,
  q3,
  q4,
  q5
} state;

state transition(state current_state, char input);

state transition(state current_state, char input) {
  switch (current_state) {
  case q0:
    return (input == '0') ? q1 : q3;
  case q1:
    return (input == '0') ? q2 : q4;
  case q2:
    return (input == '0') ? q1 : q3;
  case q3:
    return (input == '0') ? q4 : q5;
  case q4:
    return (input == '0') ? q4 : q4;
  case q5:
    return (input == '0') ? q1 : q3;
  }
}

int main() {
  state current_state = q0;
  char input_string[TAM_BUFF] = "";
  int c;
  do {

    for (int i = 0; i < TAM_BUFF && (c = getc(stdin)) != EOF && c != '\n';
         ++i) {
      input_string[i] = c;
    }

    for (int i = 0; input_string[i] != '\0'; ++i) {
      if (input_string[i] != '\n')
        current_state = transition(current_state, input_string[i]);
    }

    // verifica el estado final (Moore)
    if (current_state == q2 | current_state == q5) {
      printf("La cadena es aceptada por el automata.\n");
    } else {
      printf("la cadena es rechazada por el autómata. \n");
    }

  } while (c != EOF);
  return 0;
}
