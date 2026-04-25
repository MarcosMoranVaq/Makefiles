# ============================================================
#  Makefile – Ejemplo visto en clase
#  Curso: Sistemas Embebidos e IoT – ESCOM, IPN
# ============================================================

# --- Variables de configuración ---
CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = programa
SRCS    = main.c funciones.c
OBJS    = $(SRCS:.c=.o)

# --- Regla principal (default) ---
all: $(TARGET)

# --- Enlazado: une los .o en el ejecutable final ---
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# --- Compilación: cada .c genera su propio .o ---
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# --- Limpieza de archivos generados ---
clean:
	rm -f $(OBJS) $(TARGET)

# --- Ejecutar el programa directamente ---
run: $(TARGET)
	./$(TARGET)

# Declara que estos targets no corresponden a archivos reales
.PHONY: all clean run
