#ifndef _pilaDina_
#define _pilaDina_

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Pila{
    char dato[100];
    struct Nodo_Pila * anterior;
}Nodo_Pila;

typedef struct{
	Nodo_Pila * tope;
}Pila;
typedef Pila * PILA;

PILA crearPila ( );
int es_vaciaPila(PILA S);
Nodo_Pila * crearNodoPila(  );
char *elemTope(PILA S);
void apilar(PILA S, char *e);
char* desapilar(PILA S);


#endif

