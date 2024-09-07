#ifndef pilaDina
#define pilaDina

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Pila{
    char dato;
    struct Nodo_Pila * anterior;
}Nodo_Pila;

typedef struct{
	Nodo_Pila * tope;
}Pila;
typedef Pila * PILA;

PILA crearPila ( );
int es_vaciaPila(PILA S);
Nodo_Pila * crearNodoPila(  );
char elemTope(PILA S);
void apilar(PILA S, char e);
char desapilar(PILA S);


#endif

