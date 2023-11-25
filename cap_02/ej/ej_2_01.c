/*Ejercicio 2-1. Escriba un program a para determinar los rangos de variables
 * char, short, int y long , tanto signed como unsigned , imprim
 * iendo los valores apropia­ dos de los headers estándar y por cálculo
 * directo. Es más difícil si los calcula: de­ termine los rangos de los varios
 * tipos de punto flotante.*/
#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

int main() {

    printf("CHAR_MIN %d\n", CHAR_MIN);
    printf("CHAR_MAX %d\n", CHAR_MAX);
    printf("CHAR_MIN %d\n", CHAR_MIN);
    printf("CHAR_BIT %d\n", CHAR_BIT);
    printf("INT_MIN %d\n", INT_MIN);
    printf("INT_MAX %d\n", INT_MAX);

    // calculo de char 
    // Si n = bits =>  2^n es el rango unsigned
    // Si 1 byte = 8 bits

    int bits_char =  sizeof(char) * 8;
    printf("char min: %d\n", (int)-(pow(2, bits_char)/2));
    printf("char max: %d\n", (int)(pow(2, bits_char)/2) - 1);

    // si no se quiere usar pow crear bucle

    // ... hacer lo mismo para todos los tipos de datos

    printf("FLT_MAX %f\n", FLT_MAX);
    // Para calcular floats hay que usar IEEE 754

    
    return 0; }
