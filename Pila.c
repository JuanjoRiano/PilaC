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

// Función para inicializar la pila
void inicializarPila(Pila* pila) {
    pila->cima = NULL;
    pila->tamaño = 0;
}

// Función para verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->cima == NULL;
}

// Función para obtener el tamaño de la pila
int obtenerTamaño(Pila* pila) {
    return pila->tamaño;
}

// Función para apilar (push)
void apilar(Pila* pila, const char* dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error de memoria\n");
        return;
    }
    strncpy(nuevoNodo->dato, dato, MAX_LENGTH - 1);
    nuevoNodo->dato[MAX_LENGTH - 1] = '\0'; // Asegurar terminación nula
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
    pila->tamaño++;
}

// Función para desapilar (pop)
void desapilar(Pila* pila) {
    if (estaVacia(pila)) {
        printf("La pila está vacía, no se puede desapilar\n");
        return;
    }
    Nodo* temp = pila->cima;
    pila->cima = pila->cima->siguiente;
    free(temp);
    pila->tamaño--;
}

// Función para obtener el elemento en la cima (peek)
char* cima(Pila* pila) {
    if (estaVacia(pila)) {
        return NULL;
    }
    return pila->cima->dato;
}

// Función para limpiar la pila
void limpiarPila(Pila* pila) {
    while (!estaVacia(pila)) {
        desapilar(pila);
    }
}

// Función para imprimir la pila (de arriba hacia abajo)
void imprimirPila(Pila* pila) {
    Nodo* actual = pila->cima;
    printf("Pila:\n");
    while (actual != NULL) {
        printf("%s\n", actual->dato);
        actual = actual->siguiente;
    }
    printf("----\n");
}

// Función principal para probar la pila
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

