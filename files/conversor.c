/* src/conversor.c – Implementación de conversiones */
#include "conversor.h"

double celsius_a_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double celsius_a_kelvin(double c) {
    return c + 273.15;
}

double fahrenheit_a_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}
