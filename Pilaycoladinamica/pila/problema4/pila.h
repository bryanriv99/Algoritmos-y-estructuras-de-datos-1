#ifndef _pilaDina_
#define _pilaDina_

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Pila{
    int dato;
    struct Nodo_Pila * anterior;
}Nodo_Pila;

typedef struct{
	Nodo_Pila * tope;
}Pila;
typedef Pila * PILA;

PILA crearPila ( );
int es_vaciaPila(PILA S);
Nodo_Pila * crearNodoPila(  );
int elemTope(PILA S);
void apilar(PILA S, int e);
int desapilar(PILA S);


#endif

