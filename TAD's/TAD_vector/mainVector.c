#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
    int tamanoVector = leerDim();

    VECTOR vector1 = crearVector(tamanoVector);
    VECTOR vector2 = crearVector(tamanoVector);

    printf("Llenado del Vector 1:\n");
    llenarVector(vector1);

    printf("Llenado del Vector 2:\n");
    llenarVector(vector2);

    mostrarVector(vector1);
    mostrarVector(vector2);

    int opcion = seleccionarOperacion();
    VECTOR resultado = NULL;

    switch (opcion) {
        case 1:
            resultado = sumaVector(vector1, vector2);
            mostrarResultado(resultado);
            break;
        case 2:
            resultado = restaVector(vector1, vector2);
            mostrarResultado(resultado);
            break;
        case 3:
            printf("Producto Punto: %d\n", productoPunto(vector1, vector2));
            break;
        case 4:
            resultado = ordenaVector(vector1);
            mostrarResultado(resultado);
            break;
        default:
            printf("Opción no válida.\n");
    }

    if (resultado != NULL) {
        liberarVector(resultado);
    }
    liberarVector(vector1);
    liberarVector(vector2);

    return 0;
}
