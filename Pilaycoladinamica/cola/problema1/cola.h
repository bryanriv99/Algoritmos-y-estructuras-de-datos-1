#ifndef _colaDina_h_
#define _colaDina_h_

#define TRUE 1
#define FALSE 0

typedef struct Nodo_Cola {
    int dato;
    struct Nodo_Cola *siguiente;
} Nodo_Cola;

typedef struct {
    Nodo_Cola *primero;
    Nodo_Cola *ultimo;
} Cola;

typedef Cola *COLA;

COLA crearCola();
Nodo_Cola *crearNodoCola();
int es_vaciaCola(COLA);
int primero(COLA);
void encolar(COLA, int);
int desencolar(COLA);

#endif

