/* src/main.c
 * Conversor y analizador de temperaturas
 * Proyecto propio – Sistemas Embebidos e IoT, ESCOM IPN
 */
#include <stdio.h>
#include "conversor.h"
#include "estadisticas.h"

int main(void) {
    printf("========================================\n");
    printf("  Conversor y Analizador de Temperaturas\n");
    printf("  ESCOM – Sistemas Embebidos e IoT\n");
    printf("========================================\n\n");

    /* Lecturas simuladas de sensor en Celsius */
    double lecturas[] = {22.5, 36.7, 100.0, 0.0, -40.0, 37.0, 25.3};
    int n = sizeof(lecturas) / sizeof(lecturas[0]);

    printf("%-12s %-12s %-12s\n", "Celsius", "Fahrenheit", "Kelvin");
    printf("%-12s %-12s %-12s\n", "-------", "----------", "------");

    for (int i = 0; i < n; i++) {
        double f = celsius_a_fahrenheit(lecturas[i]);
        double k = celsius_a_kelvin(lecturas[i]);
        printf("%-12.2f %-12.2f %-12.2f\n", lecturas[i], f, k);
    }

    printf("\n--- Estadisticas de las lecturas (Celsius) ---\n");
    printf("Minima  : %.2f C\n", minimo(lecturas, n));
    printf("Maxima  : %.2f C\n", maximo(lecturas, n));
    printf("Promedio: %.2f C\n", promedio(lecturas, n));

    return 0;
}
