#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int *elementos;
    int tamano;
} Vector;

typedef Vector *VECTOR;

VECTOR crearVector(int tamano);
int obtenComponente(VECTOR vector, int indice);
VECTOR asignaComponente(VECTOR vector, int indice, int valor);
int tamano(VECTOR vector);
VECTOR sumaVector(VECTOR vector1, VECTOR vector2);
VECTOR restaVector(VECTOR vector1, VECTOR vector2);
int productoPunto(VECTOR vector1, VECTOR vector2);
VECTOR ordenaVector(VECTOR vector);
void liberarVector(VECTOR vector);
void mostrarVector(VECTOR vector);
void llenarVector(VECTOR vector);
int seleccionarOperacion();
void mostrarResultado(VECTOR resultado);
int leerDim();

#endif
