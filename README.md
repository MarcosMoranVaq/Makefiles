# Análisis del Makefile de Ejemplo
**Materia:** Sistemas Embebidos e IoT  
**Escuela:** ESCOM – IPN  
**Repositorio base:** [alemanmig/Embedded-Systems-IoT](https://github.com/alemanmig/Embedded-Systems-IoT/tree/main/Makefiles)

---

## ¿Qué es este proyecto?

Este ejercicio reproduce el Makefile visto en clase. El programa en C está dividido en tres archivos (`main.c`, `funciones.c`, `funciones.h`) y el Makefile se encarga de compilarlos, enlazarlos y limpiar los archivos temporales de forma automática, sin tener que escribir los comandos de GCC a mano cada vez.

---

## Estructura del repositorio

```
ejemplo_repo/
├── Makefile       ← Archivo de automatización
├── main.c         ← Punto de entrada del programa
├── funciones.c    ← Implementación de funciones auxiliares
└── funciones.h    ← Cabeceras / declaraciones
```

---

## Cómo ejecutar el proyecto

### Requisitos previos
- Sistema operativo Linux (o WSL en Windows)
- GCC instalado (`sudo apt install gcc` en Debian/Ubuntu)
- Make instalado (`sudo apt install make`)

### Pasos

```bash
# 1. Clonar o entrar a la carpeta del proyecto
cd ejemplo_repo

# 2. Compilar todo el proyecto
make

# 3. Ejecutar el programa generado
./programa

# 4. (Opcional) Compilar y ejecutar de un solo golpe
make run

# 5. Limpiar archivos generados (.o y el ejecutable)
make clean
```

### Salida esperada al correr `./programa`
```
=== Programa de ejemplo – Makefiles ===
Hola desde ESCOM!
Resultado de 10 + 25 = 35
```

---

## Análisis detallado del Makefile

### Variables definidas al inicio

```makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -g
TARGET  = programa
SRCS    = main.c funciones.c
OBJS    = $(SRCS:.c=.o)
```

Estas líneas definen "constantes" que se reutilizan en todo el archivo. `CC` indica qué compilador usar; `CFLAGS` son las banderas de compilación (`-Wall` activa todas las advertencias, `-Wextra` agrega advertencias extra, y `-g` incluye información de depuración). `SRCS` lista los archivos fuente y `OBJS` genera automáticamente la lista de archivos objeto cambiando la extensión `.c` por `.o`.

### Target `all` (compilación completa)

```makefile
all: $(TARGET)
```

Es el target por defecto. Cuando escribes `make` sin argumentos, Make busca el primer target del archivo, que en este caso es `all`. A su vez, `all` depende de `$(TARGET)` (es decir, del ejecutable `programa`).

### Target de enlazado

```makefile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
```

Esta regla le dice a Make: *para producir el ejecutable `programa`, primero necesito todos los archivos `.o`; luego los uno con GCC*. Si algún `.o` ya existe y no cambió, Make no lo recompila, lo que ahorra tiempo en proyectos grandes.

### Regla de compilación (patrón)

```makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

La sintaxis `%.o: %.c` es una **regla de patrón**: significa "para cualquier `.o`, búscame el `.c` correspondiente". La variable automática `$<` representa el archivo fuente (el `.c`) y `$@` representa el objetivo (el `.o`). El flag `-c` le indica a GCC que solo compile, sin enlazar todavía.

### Target `clean`

```makefile
clean:
	rm -f $(OBJS) $(TARGET)
```

Elimina todos los archivos generados. Es útil cuando quieres empezar una compilación desde cero o antes de entregar el código sin basura.

### Target `run`

```makefile
run: $(TARGET)
	./$(TARGET)
```

Compila (si hace falta) y ejecuta el programa en un solo comando. Conveniente durante el desarrollo.

### Directiva `.PHONY`

```makefile
.PHONY: all clean run
```

Le avisa a Make que `all`, `clean` y `run` **no son archivos reales**. Sin esto, si existiera un archivo llamado `clean` en la carpeta, Make pensaría que ya está "al día" y no ejecutaría el comando.

---

## ¿Cómo contribuye este Makefile a la automatización?

Sin Makefile, para compilar este proyecto tendrías que escribir:

```bash
gcc -Wall -Wextra -g -c main.c -o main.o
gcc -Wall -Wextra -g -c funciones.c -o funciones.o
gcc -Wall -Wextra -g -o programa main.o funciones.o
```

Con el Makefile, basta con `make`. Además, Make es inteligente: detecta qué archivos cambiaron y solo recompila lo necesario. En proyectos con decenas de archivos, esto puede ahorrar minutos de espera.

---

## Resultados de ejecución

```
$ make
gcc -Wall -Wextra -g -c main.c -o main.o
gcc -Wall -Wextra -g -c funciones.c -o funciones.o
gcc -Wall -Wextra -g -o programa main.o funciones.o

$ ./programa
=== Programa de ejemplo – Makefiles ===
Hola desde ESCOM!
Resultado de 10 + 25 = 35

$ make clean
rm -f main.o funciones.o programa
```

Make imprime cada comando antes de ejecutarlo, lo que facilita ver exactamente qué está pasando en cada paso de la compilación.
