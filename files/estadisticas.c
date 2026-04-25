/* src/estadisticas.c – Implementación de estadísticas */
#include "estadisticas.h"

double minimo(const double *arr, int n) {
    double m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < m) m = arr[i];
    return m;
}

double maximo(const double *arr, int n) {
    double m = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > m) m = arr[i];
    return m;
}

double promedio(const double *arr, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++)
        suma += arr[i];
    return suma / n;
}
