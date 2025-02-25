# Implementación de una Pila en C

Este proyecto implementa una pila en el lenguaje C sin utilizar bibliotecas de cabecera externas, excepto `stdio.h` y `stdlib.h`. Todas las funciones y la estructura de datos están en un solo archivo, cumpliendo con los requisitos de no usar `string.h` ni archivos separados.

## Descripción
Una **pila** (stack) es una estructura de datos de tipo LIFO (*Last In, First Out*), donde el último elemento agregado es el primero en ser retirado.

Las operaciones básicas de la pila incluyen:
- **Push**: Insertar un elemento en la cima de la pila.
- **Pop**: Retirar el elemento superior de la pila.
- **Peek**: Obtener el valor del elemento superior sin retirarlo.
- **isEmpty**: Comprobar si la pila está vacía.
- **isFull**: Comprobar si la pila está llena.

## Estructura del Código
El código está estructurado en las siguientes partes:

### 1. Definición de la Estructura `Pila`
```c
#define MAX 100

typedef struct {
    int datos[MAX]; // Arreglo donde se almacenan los datos de la pila
    int tope;       // Índice del elemento en la cima
} Pila;
```

### 2. Funciones de la Pila
#### a) Inicializar la Pila
```c
void inicializar(Pila *p) {
    p->tope = -1;
}
```
Esta función establece el índice `tope` en `-1`, indicando que la pila está vacía.

#### b) Verificar si la Pila está Vacía
```c
int estaVacia(Pila *p) {
    return p->tope == -1;
}
```
Devuelve `1` si la pila está vacía y `0` en caso contrario.

#### c) Verificar si la Pila está Llena
```c
int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}
```
Devuelve `1` si la pila está llena y `0` en caso contrario.

#### d) Insertar un Elemento (`push`)
```c
void push(Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("Error: la pila está llena\n");
        return;
    }
    p->tope++;
    p->datos[p->tope] = valor;
}
```
Si la pila no está llena, aumenta el índice `tope` y almacena el nuevo valor en esa posición.

#### e) Extraer un Elemento (`pop`)
```c
int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    int valor = p->datos[p->tope];
    p->tope--;
    return valor;
}
```
Si la pila no está vacía, se obtiene el elemento superior y se reduce el índice `tope`.

#### f) Obtener el Elemento en la Cima (`peek`)
```c
int peek(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    return p->datos[p->tope];
}
```
Devuelve el valor del elemento superior sin modificar la pila.

### 3. Función Principal (`main`)
```c
int main() {
    Pila miPila;
    inicializar(&miPila);

    push(&miPila, 10);
    push(&miPila, 20);
    push(&miPila, 30);

    printf("Elemento en la cima: %d\n", peek(&miPila));
    printf("Sacando elementos: %d\n", pop(&miPila));
    printf("Sacando elementos: %d\n", pop(&miPila));
    printf("Elemento en la cima: %d\n", peek(&miPila));

    return 0;
}
```
En esta función:
1. Se inicializa la pila.
2. Se agregan tres elementos (`10`, `20`, `30`).
3. Se muestra el elemento en la cima.
4. Se extraen elementos y se imprime el resultado.


## Ejemplo de Salida
```
Elemento en la cima: 30
Sacando elementos: 30
Sacando elementos: 20
Elemento en la cima: 10
```


