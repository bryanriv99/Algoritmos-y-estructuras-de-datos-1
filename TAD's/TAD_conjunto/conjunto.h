#ifndef _conjunto_
#define _conjunto_

typedef struct {
    int *elementos;
    int capacidad;
    int tamano;
} Conjunto;

typedef Conjunto* CONJUNTO;

Conjunto* ConjuntoVacio(int tamano);
void Añadir(CONJUNTO conjunto, int elemento);
void Retirar(CONJUNTO conjunto, int elemento);
int Pertenece(CONJUNTO conjunto, int elemento);
int EsVacio(CONJUNTO conjunto);
int Cardinal(CONJUNTO conjunto);
CONJUNTO Union(CONJUNTO conjunto1, CONJUNTO conjunto2);
CONJUNTO Interseccion(CONJUNTO conjunto1, CONJUNTO conjunto2);
int Inclusion(CONJUNTO conjunto1, CONJUNTO conjunto2);

#endif
