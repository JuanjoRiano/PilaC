#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Tamaño máximo de la pila

// Definición de la estructura de la pila
typedef struct {
    int datos[MAX]; // Arreglo para almacenar los datos
    int tope;       // Índice del tope de la pila
} Pila;

// Función para inicializar la pila
void inicializar(Pila *p) {
    p->tope = -1;
}

// Función para verificar si la pila está vacía
int estaVacia(Pila *p) {
    return p->tope == -1;
}

// Función para verificar si la pila está llena
int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

// Función para agregar un elemento a la pila
void push(Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("Error: la pila está llena\n");
        return;
    }
    p->tope++;
    p->datos[p->tope] = valor;
}

// Función para sacar un elemento de la pila
int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: la pila está vacía\n");
        return -1; 
    }
    int valor = p->datos[p->tope];
    p->tope--;
    return valor;
}

// Función para ver el elemento en la cima sin sacarlo
int peek(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: la pila está vacía\n");
        return -1;
    }
    return p->datos[p->tope];
}

// Función principal para probar la pila
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
