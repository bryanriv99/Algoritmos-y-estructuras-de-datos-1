#include "conjunto.h"

int main() {
    CONJUNTO conjunto1 = ConjuntoVacio(10);
    CONJUNTO conjunto2 = ConjuntoVacio(10);

    Añadir(conjunto1, 1);
    Añadir(conjunto1, 2);
    Añadir(conjunto1, 3);

    Añadir(conjunto2, 2);
    Añadir(conjunto2, 3);
    Añadir(conjunto2, 4);

    printf("Conjunto 1: {1, 2, 3}\n");
    printf("Conjunto 2: {2, 3, 4}\n");

    CONJUNTO unionConjuntos = Union(conjunto1, conjunto2);
    CONJUNTO interseccionConjuntos = Interseccion(conjunto1, conjunto2);

    printf("Unión de Conjunto 1 y Conjunto 2: ");
    for (int i = 0; i < unionConjuntos->tamano; i++) {
        printf("%d ", unionConjuntos->elementos[i]);
    }
    printf("\n");

    printf("Intersección de Conjunto 1 y Conjunto 2: ");
    for (int i = 0; i < interseccionConjuntos->tamano; i++) {
        printf("%d ", interseccionConjuntos->elementos[i]);
    }
    printf("\n");

    if (Inclusion(conjunto1, conjunto2)) {
        printf("Conjunto 1 está incluido en Conjunto 2.\n");
    } else {
        printf("Conjunto 1 no está incluido en Conjunto 2.\n");
    }

    free(conjunto1->elementos);
    free(conjunto1);
    free(conjunto2->elementos);
    free(conjunto2);
    free(unionConjuntos->elementos);
    free(unionConjuntos);
    free(interseccionConjuntos->elementos);
    free(interseccionConjuntos);

    return 0;
}
