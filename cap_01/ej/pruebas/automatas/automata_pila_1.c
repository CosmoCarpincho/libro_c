/* Un NPDA  L = {(a^nb^n)^n | n >= 0}
Cadena de a seguida de la misma cantidad de b
Veo poco practico crear una matriz para los cambios de estado.
Creo que lo mejor es hacerlo con case o if por cada simbolo.

La pila la voy a hacer con un arreglo no con malloc.

*/

#include <stdio.h>

#define MAX_PILA 1000

struct pila {
    int top;
    char simbolos[MAX_PILA];
};
// funciones pila
void initialize(struct pila **p);
int is_empty(struct pila *p);
int is_full(struct pila *p);
void push(struct pila *p, char c);
char pop(struct pila *p);


void initialize(struct pila **p){
    struct pila n = {-1, '\0'};
    *p = &n;
}

int is_empty(struct pila *p){
    return p->top == -1;
}

int is_full(struct pila *p){
   return p->top > MAX_PILA - 1;
}

void push(struct pila *p, char c){
    if (is_full(p))
        printf("Desbordamiento de pila\n");
    else
        p->simbolos[++(p->top)] = c;
}

char pop(struct pila *p){
    if (is_empty(p)){
        printf("Se llego a la base de la pila\n");
        return '\0';
    }
    else
        return p->simbolos[(p->top)--];
}



int is_valid(char *texto);

int is_valid(char *texto){
    struct pila *pila;
    initialize(&pila);

    int i;
    for (i = 0; texto[i] != '\0'; ++i)
    {
        switch (texto[i]){
            case 'a':
                push(pila, 'a');
                break;
            case 'b':
                if(!is_empty(pila))
                    pop(pila);
                else
                    return 0; // No hay mas  'a' en la pila
                break;
            default:
                printf("Caracter no válido %c\n", texto[i]);
                break;
        }
    
    }

    return 1; // Exito
}


int main(void){
    // Leer la entrada
    char texto[MAX_PILA];
    printf("Escriba el texto a validar: ");
    scanf("%s", &texto);

    if (is_valid(texto)){
        printf("La cadena pertenece al lenguaje. \n");
    }
    else {
        printf("La cadena no pertenece al lenguaje. \n");

    }
    return 0;
}