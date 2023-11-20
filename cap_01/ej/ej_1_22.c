/*Ejercicio 1-22. Escriba un programa para “doblar” líneas grandes de
 * entrada en dos o más líneas más cortas después del último carácter no blanco
 * que ocurra antes de la n-ésima colum na de entrada. Asegúrese de que su
 * programa se comporte apropiadam ente con líneas muy largas, y de que no hay
 * blancos o tabuladores antes de la columna especificada.*/

/* Cosmo:
 * Dos buffers que guardan un caracter mas de las columnas para verificar
 * palabra recortada.
 * Se imprime primero uno y despues el otro en bucle si la
 * palabra desborda las columnas retroceder en el buffer y guardar en el otro
 * si una sola palabra pasa las columnas cortar la palabra no queda otra
 * */

#include <stdio.h>

#define ON_BUFF_1 0
#define ON_BUFF_2 1
#define N_COLUMNS 8
// Tiene +1 por caracter siguiente
#define N_TOTAL_CHAR (N_COLUMNS + 1)

int load_buffer(char buff[], int init, int n_total_char);
int load_other_buffer(char buff[], char buff2[], int n_total_char,
                      int n_final_char);

// Retorna 0 .. n  números de caracteres que hay pasar al otro buffer
// Retorna EOF cuando ya no hay mas datos de stdin
int load_buffer(char buff[], int init, int n_total_char) {

  int n_final_char = 0;
  int c, i;
  for (i = init; i < N_TOTAL_CHAR && (c = getchar()) != EOF; ++i) {
    buff[i] = c;
    if (c != ' ' && c != '\t' && c != '\n')
      ++n_final_char;
    else
      n_final_char = 0;
  }
  buff[i] = '\0';

  if (c == EOF)
    return EOF;

  return n_final_char;
}

// Retorna cuantos caracteres agrego
int load_other_buffer(char buff[], char buff2[], int n_total_char,
                      int n_final_char) {
  int i;
  int i_first_final_char = n_total_char - n_final_char;
  for (i = 0; i < n_final_char; ++i) {
    buff2[i] = buff[i + i_first_final_char];
  }
  buff2[i] = '\0';
  buff[i_first_final_char] = '\0';

  return i;
}

int main() {
  //
  int state = ON_BUFF_1;
  char buff[N_TOTAL_CHAR + 1];
  char buff2[N_TOTAL_CHAR + 1];
  char *p_buffer;
  char *p_other_buffer;
  int n_final_char = 0;
  int init = 0;

  do {

    // swap buffers
    if (state == ON_BUFF_1) {
      p_buffer = buff;
      p_other_buffer = buff2;
      state = ON_BUFF_2;
    } else if (state == ON_BUFF_2) {
      p_buffer = buff2;
      p_other_buffer = buff;
      state = ON_BUFF_1;
    }

    n_final_char = load_buffer(p_buffer, init, N_TOTAL_CHAR);

    if (n_final_char > 0 && n_final_char != N_TOTAL_CHAR) {
      init = load_other_buffer(p_buffer, p_other_buffer, N_TOTAL_CHAR,
                               n_final_char);
    } else {
      init = 0;
      if (n_final_char != EOF)
        n_final_char = 0;
    }
    printf("%s", p_buffer);
    if (p_buffer[N_TOTAL_CHAR - n_final_char - 1] != '\n') {
      printf("\n");
    }

  } while (n_final_char != EOF);

  return 0;
}
