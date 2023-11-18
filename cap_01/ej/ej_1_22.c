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

// Retorna 0 .. n  númeors de caracteres que hay pasar al otro buffer
// Retorna EOF cuando ya no hay mas datos de stdin
int load_buffer(char buff[], int init, int n_total_char) {

  int n_final_char = 0;
  int c, i;
  for (i = init; i < N_TOTAL_CHAR && (c = getchar()) != EOF; ++i) {
    buff[i] = c;
    if (c != ' ' && c != '\t' && c != '\n')
      ++n_final_char;
    else {
      n_final_char = 0;
      if (i == N_TOTAL_CHAR - 1) {
        buff[i - 1] = '\n'; // ver esto
        break;              // ver esto
      }
    }
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
  for (i = 0; i < n_final_char; ++i) {
    buff2[i] = buff[i + n_total_char];
  }

  buff[N_TOTAL_CHAR - n_final_char] = '\n';     // ver esto
  buff[N_TOTAL_CHAR - n_final_char + 1] = '\0'; // ver esto

  return i;
}

int main() {
  //
  int state = ON_BUFF_1;
  char buff[N_TOTAL_CHAR];
  char buff2[N_TOTAL_CHAR];
  int n_final_char = 0;
  int init = 0;

  do {

    if (state == ON_BUFF_1) {
      n_final_char = load_buffer(buff, n_final_char, N_TOTAL_CHAR);
      init = load_other_buffer(buff, buff2, N_TOTAL_CHAR, n_final_char);
      buff[N_TOTAL_CHAR - n_final_char] = '\n';
      printf("%s", buff);
      state = ON_BUFF_2;

    } else if (state == ON_BUFF_2) {
      n_final_char = load_buffer(buff2, n_final_char, N_TOTAL_CHAR);
      init = load_other_buffer(buff2, buff, N_TOTAL_CHAR, n_final_char);
      printf("%s", buff2);
      state = ON_BUFF_1;
    }

  } while (n_final_char != EOF);

  return 0;
}
