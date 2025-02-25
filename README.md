# Pila en C (Stack)

Este proyecto es una implementación de una **pila (stack) en C** utilizando **listas enlazadas** para almacenar **cadenas de texto (********`char*`********)**. No se usan archivos de cabecera, por lo que todo el código está en un solo archivo para facilitar su uso.

## 📌 Características

- **Estructura de datos tipo pila** implementada con listas enlazadas.
- **Funciones básicas:**
  - `apilar()` (Push) → Agregar un elemento.
  - `desapilar()` (Pop) → Eliminar el elemento superior.
  - `cima()` (Peek) → Obtener el elemento superior sin eliminarlo.
  - `estaVacia()` (isEmpty) → Verificar si la pila está vacía.
  - `obtenerTamaño()` (Size) → Obtener el número de elementos en la pila.
  - `limpiarPila()` (Clear) → Vaciar la pila completamente.
  - `imprimirPila()` → Mostrar el contenido de la pila.
- **Gestión de memoria dinámica** con `malloc()` y `free()`.

## 📂 Estructura del Código

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100  // Tamaño máximo para las cadenas

// Definición del nodo
typedef struct Nodo {
    char dato[MAX_LENGTH];
    struct Nodo* siguiente;
} Nodo;

// Definición de la pila
typedef struct {
    Nodo* cima;
    int tamaño;
} Pila;
```

### 🔹 Inicialización de la pila

```c
void inicializarPila(Pila* pila) {
    pila->cima = NULL;
    pila->tamaño = 0;
}
```

### 🔹 Verificar si la pila está vacía

```c
int estaVacia(Pila* pila) {
    return pila->cima == NULL;
}
```

### 🔹 Obtener el tamaño de la pila

```c
int obtenerTamaño(Pila* pila) {
    return pila->tamaño;
}
```

### 🔹 Apilar un elemento

```c
void apilar(Pila* pila, const char* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error de memoria\n");
        return;
    }
    strncpy(nuevoNodo->dato, dato, MAX_LENGTH - 1);
    nuevoNodo->dato[MAX_LENGTH - 1] = '\0';
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
    pila->tamaño++;
}
```

### 🔹 Desapilar un elemento

```c
void desapilar(Pila* pila) {
    if (estaVacia(pila)) {
        printf("La pila está vacía\n");
        return;
    }
    Nodo* temp = pila->cima;
    pila->cima = pila->cima->siguiente;
    free(temp);
    pila->tamaño--;
}
```

### 🔹 Obtener el elemento superior (sin eliminarlo)

```c
char* cima(Pila* pila) {
    if (estaVacia(pila)) {
        return NULL;
    }
    return pila->cima->dato;
}
```

### 🔹 Limpiar la pila completamente

```c
void limpiarPila(Pila* pila) {
    while (!estaVacia(pila)) {
        desapilar(pila);
    }
}
```

### 🔹 Imprimir el contenido de la pila

```c
void imprimirPila(Pila* pila) {
    Nodo* actual = pila->cima;
    printf("Pila (de arriba hacia abajo):\n");
    while (actual != NULL) {
        printf("%s\n", actual->dato);
        actual = actual->siguiente;
    }
    printf("----\n");
}
```

## 🚀 Uso en `main()`

```c
int main() {
    Pila pila;
    inicializarPila(&pila);

    apilar(&pila, "Uno");
    apilar(&pila, "Dos");
    apilar(&pila, "Tres");

    imprimirPila(&pila);
    printf("Cima de la pila: %s\n", cima(&pila));
    printf("Tamaño de la pila: %d\n", obtenerTamaño(&pila));

    desapilar(&pila);
    imprimirPila(&pila);
    printf("Tamaño después de desapilar: %d\n", obtenerTamaño(&pila));

    limpiarPila(&pila);
    printf("Pila limpiada. ¿Está vacía? %s\n", estaVacia(&pila) ? "Sí" : "No");

    return 0;
}
```

## 📌 Ejemplo de Salida

```sh
Pila (de arriba hacia abajo):
Tres
Dos
Uno
----
Cima de la pila: Tres
Tamaño de la pila: 3

Pila (de arriba hacia abajo):
Dos
Uno
----
Tamaño después de desapilar: 2

Pila limpiada. ¿Está vacía? Sí
```

## 📖 Explicación

1. **Se inicializa** la pila.
2. **Se apilan** tres elementos (`"Uno"`, `"Dos"`, `"Tres"`).
3. **Se imprime** la pila y se obtiene la cima.
4. **Se desapila** un elemento y se vuelve a imprimir.
5. **Se limpia** la pila y se verifica si está vacía.

## 📜 Notas

- El código usa `malloc()` para la memoria dinámica, por lo que es importante llamar a `limpiarPila()` al final.
- Se usa `strncpy()` para evitar desbordamientos de buffer.
- El `#define MAX_LENGTH 100` limita el tamaño de las cadenas almacenadas.

##
