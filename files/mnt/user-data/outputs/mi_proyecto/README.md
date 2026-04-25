# Conversor y Analizador de Temperaturas
**Materia:** Sistemas Embebidos e IoT  
**Escuela:** ESCOM – IPN  
**Proyecto propio con Makefile**

---

## Descripción del proyecto

Este programa toma un conjunto de lecturas de temperatura en grados Celsius (como las que podría enviar un sensor de temperatura en un sistema embebido) y las convierte a Fahrenheit y Kelvin. Además calcula estadísticas básicas: mínimo, máximo y promedio del conjunto de lecturas.

El proyecto está dividido en módulos separados para mantener el código ordenado y reutilizable, y usa un Makefile para automatizar la compilación de todos esos módulos.

---

## Estructura del repositorio

```
mi_proyecto/
├── Makefile               ← Automatiza la compilación
├── .gitignore             ← Excluye archivos innecesarios
├── README.md              ← Esta documentación
└── src/
    ├── main.c             ← Programa principal
    ├── conversor.c        ← Lógica de conversión de temperaturas
    ├── conversor.h        ← Cabeceras del módulo conversor
    ├── estadisticas.c     ← Cálculo de min, max y promedio
    └── estadisticas.h     ← Cabeceras del módulo estadísticas
```

Los archivos objeto (`.o`) y el ejecutable se generan en la carpeta `build/`, la cual es creada automáticamente por el Makefile y está excluida del repositorio con `.gitignore`.

---

## Requisitos

- Linux o macOS (o WSL en Windows)
- GCC (`sudo apt install gcc`)
- Make (`sudo apt install make`)

---

## Cómo compilar y ejecutar

```bash
# Compilar el proyecto completo
make

# Compilar y ejecutar directamente
make run

# Limpiar todos los archivos generados
make clean

# Ver los comandos disponibles
make help
```

---

## Salida esperada

```
========================================
  Conversor y Analizador de Temperaturas
  ESCOM – Sistemas Embebidos e IoT
========================================

Celsius      Fahrenheit   Kelvin
-------      ----------   ------
22.50        72.50        295.65
36.70        98.06        309.85
100.00       212.00       373.15
0.00         32.00        273.15
-40.00       -40.00       233.15
37.00        98.60        310.15
25.30        77.54        298.45

--- Estadisticas de las lecturas (Celsius) ---
Minima  : -40.00 C
Maxima  : 100.00 C
Promedio: 25.93 C
```

---

## Explicación del Makefile

### Variables principales

```makefile
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c11 -g
TARGET  = temp_analyzer
SRCS    = src/main.c src/conversor.c src/estadisticas.c
OBJS    = $(SRCS:src/%.c=build/%.o)
```

`CC` define el compilador. `CFLAGS` incluye `-Wpedantic` y `-std=c11` para asegurarse de que el código cumpla con el estándar C11. `OBJS` usa una **sustitución de texto**: toma cada `src/X.c` y lo convierte en `build/X.o`, de modo que los archivos objeto queden separados del código fuente.

### Creación automática del directorio `build/`

```makefile
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
```

Si la carpeta `build/` no existe, Make la crea antes de intentar guardar los `.o` dentro. Esto evita errores manuales.

### Regla de compilación de módulos

```makefile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
```

Cada archivo `.c` dentro de `src/` se compila por separado y su resultado `.o` se guarda en `build/`. Gracias a esto, si solo modificas `conversor.c`, Make únicamente recompila ese módulo y vuelve a enlazar; los demás `.o` no se tocan.

### Target `help`

```makefile
help:
	@echo "Comandos disponibles:"
	...
```

El `@` al inicio de la línea hace que Make no imprima el comando en sí, solo su salida. Esto es útil para mensajes informativos limpios.

---

## ¿Por qué usar Makefile?

En un proyecto embebido real puedes tener decenas de archivos fuente. Compilarlos manualmente uno por uno es lento y propenso a errores. El Makefile resuelve esto de tres formas:

1. **Automatización**: un solo comando compila todo el proyecto.
2. **Compilación incremental**: solo recompila lo que cambió, no todo.
3. **Estandarización**: cualquier persona que clone el repositorio puede compilar el proyecto con exactamente los mismos flags y estructura, sin importar su entorno.

---

## Archivos excluidos por .gitignore

El `.gitignore` excluye la carpeta `build/` completa, el ejecutable `temp_analyzer` y archivos temporales de editores. Esto mantiene el repositorio limpio: solo se sube el código fuente necesario para reproducir el proyecto.
