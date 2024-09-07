#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

Conjunto* ConjuntoVacio(int tamano) {
    Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto->elementos = (int *)malloc(tamano * sizeof(int));
    conjunto->capacidad = tamano;
    conjunto->tamano = 0;
    return conjunto;
}

void Añadir(CONJUNTO conjunto, int elemento) {
    if (!Pertenece(conjunto, elemento)) {
        if (conjunto->tamano == conjunto->capacidad) {
            conjunto->capacidad *= 2;
            conjunto->elementos = (int *)realloc(conjunto->elementos, conjunto->capacidad * sizeof(int));
        }
        conjunto->elementos[conjunto->tamano] = elemento;
        conjunto->tamano++;
    }
}

void Retirar(CONJUNTO conjunto, int elemento) {
    int i;
    for (i = 0; i < conjunto->tamano; i++) {
        if (conjunto->elementos[i] == elemento) {
            for (int j = i; j < conjunto->tamano - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamano--;
            break;
        }
    }
}

int Pertenece(CONJUNTO conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamano; i++) {
        if (conjunto->elementos[i] == elemento) {
            return 1; // Verdadero
        }
    }
    return 0; // Falso
}

int EsVacio(CONJUNTO conjunto) {
    return (conjunto->tamano == 0);
}

int Cardinal(CONJUNTO conjunto) {
    return conjunto->tamano;
}

CONJUNTO Union(CONJUNTO conjunto1, CONJUNTO conjunto2) {
    CONJUNTO resultado = ConjuntoVacio(conjunto1->capacidad + conjunto2->tamano);
    for (int i = 0; i < conjunto1->tamano; i++) {
        Añadir(resultado, conjunto1->elementos[i]);
    }
    for (int i = 0; i < conjunto2->tamano; i++) {
        Añadir(resultado, conjunto2->elementos[i]);
    }
    return resultado;
}

CONJUNTO Interseccion(CONJUNTO conjunto1, CONJUNTO conjunto2) {
    CONJUNTO resultado = ConjuntoVacio(conjunto1->tamano);
    for (int i = 0; i < conjunto1->tamano; i++) {
        if (Pertenece(conjunto2, conjunto1->elementos[i])) {
            Añadir(resultado, conjunto1->elementos[i]);
        }
    }
    return resultado;
}

int Inclusion(CONJUNTO conjunto1, CONJUNTO conjunto2) {
    for (int i = 0; i < conjunto1->tamano; i++) {
        if (!Pertenece(conjunto2, conjunto1->elementos[i])) {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
}
