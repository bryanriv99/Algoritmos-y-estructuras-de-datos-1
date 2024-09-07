
#ifndef _colaDina_h_
#define _colaDina_h_

#define TRUE 1
#define FALSE 0

typedef struct {
    int noCliente;
    char nombre[50];
    int estado;
    int monto;
} Cliente;

typedef struct Nodo_Cola {
    Cliente dato;
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
void encolar(COLA, Cliente);
Cliente desencolar(COLA);

#endif
