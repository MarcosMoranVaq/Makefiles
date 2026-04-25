/* main.c – Punto de entrada del programa de ejemplo */
#include <stdio.h>
#include "funciones.h"

int main(void) {
    printf("=== Programa de ejemplo – Makefiles ===\n");
    saludar("ESCOM");
    int resultado = sumar(10, 25);
    printf("Resultado de 10 + 25 = %d\n", resultado);
    return 0;
}
