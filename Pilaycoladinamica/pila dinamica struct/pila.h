#ifndef pilaDina
#define pilaDina

#define TRUE 1
#define FALSE 0

typedef struct {
    int placa;
    char estado[3];
    char marca[25];
    char modelo[25];
    int año;
    char propietario[25];
} Vehiculo;

typedef struct Nodo_Pila {
    Vehiculo dato;
    struct Nodo_Pila *anterior;
} Nodo_Pila;

typedef struct {
    Nodo_Pila *tope;
} Pila;

typedef Pila *PILA;

PILA crearPila();
int es_vaciaPila(PILA S);
Nodo_Pila *crearNodoPila();
Vehiculo elemTope(PILA S);
void apilar(PILA S, Vehiculo e);
Vehiculo desapilar(PILA S);

#endif
