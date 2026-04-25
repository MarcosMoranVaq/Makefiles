# ============================================================
#  Makefile – Conversor y analizador de temperaturas
#  Proyecto propio – Sistemas Embebidos e IoT, ESCOM IPN
# ============================================================

# --- Compilador y banderas ---
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -g
LDFLAGS =

# --- Nombres del ejecutable y fuentes ---
TARGET  = temp_analyzer
SRCS    = src/main.c src/conversor.c src/estadisticas.c
OBJS    = $(SRCS:src/%.c=build/%.o)

# --- Directorios ---
SRC_DIR   = src
BUILD_DIR = build

# ============================================================
#  Reglas
# ============================================================

# Target por defecto
all: $(BUILD_DIR) $(TARGET)

# Crear directorio build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Enlazado final
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	@echo ">>> Compilacion exitosa: $(TARGET)"

# Compilacion de cada modulo
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar todo lo generado
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo ">>> Limpieza completa"

# Compilar y ejecutar
run: all
	./$(TARGET)

# Mostrar ayuda
help:
	@echo "Comandos disponibles:"
	@echo "  make        -> Compila el proyecto"
	@echo "  make run    -> Compila y ejecuta"
	@echo "  make clean  -> Elimina archivos generados"
	@echo "  make help   -> Muestra este mensaje"

.PHONY: all clean run help
