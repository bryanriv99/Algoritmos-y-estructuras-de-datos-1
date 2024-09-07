#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

VECTOR crearVector(int tamano) {
    VECTOR nuevoVector = (VECTOR)malloc(sizeof(Vector));
    if (nuevoVector == NULL) {
        perror("Error al asignar memoria para el vector");
        exit(1);
    }

    nuevoVector->tamano = tamano;
    nuevoVector->elementos = (int*)malloc(tamano * sizeof(int));
    if (nuevoVector->elementos == NULL) {
        perror("Error al asignar memoria para los elementos del vector");
        exit(1);
    }

    return nuevoVector;
}

int obtenComponente(VECTOR vector, int indice) {
    if (indice >= 0 && indice < vector->tamano) {
        return vector->elementos[indice];
    }
    return 0; // Valor predeterminado en caso de índice inválido
}

VECTOR asignaComponente(VECTOR vector, int indice, int valor) {
    if (indice >= 0 && indice < vector->tamano) {
        vector->elementos[indice] = valor;
    }
    return vector;
}

int tamano(VECTOR vector) {
    return vector->tamano;
}

// Implementa el resto de las funciones de acuerdo a tu lógica.

void liberarVector(VECTOR vector) {
    if (vector != NULL) {
        free(vector->elementos);
        free(vector);
    }
}

void mostrarVector(VECTOR vector) {
    printf("Contenido del vector:\n");
    for (int i = 0; i < vector->tamano; i++) {
        printf("%d ", vector->elementos[i]);
    }
    printf("\n");
}

void llenarVector(VECTOR vector) {
    for (int i = 0; i < vector->tamano; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &vector->elementos[i]);
    }
}

int seleccionarOperacion() {
    int opcion;
    printf("Seleccione la operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Producto Punto\n");
    printf("4. Ordenar\n");
    printf("Elija una opción (1-4): ");
    scanf("%d", &opcion);
    return opcion;
}

void mostrarResultado(VECTOR resultado) {
    printf("Resultado de la operación:\n");
    mostrarVector(resultado);
}

int leerDim() {
    int tamanoVector;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &tamanoVector);
    return tamanoVector;
}
