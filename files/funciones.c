/* funciones.c – Implementación de funciones auxiliares */
#include <stdio.h>
#include "funciones.h"

void saludar(const char *nombre) {
    printf("Hola desde %s!\n", nombre);
}

int sumar(int a, int b) {
    return a + b;
}
