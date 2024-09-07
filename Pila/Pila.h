
#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 2

typedef struct{
	int pila[TAMPILA];
	int tope;
}Pila;

typedef Pila* PILA;

PILA crearPila();
void apilar(PILA S, int e);
int es_vaciaPila(PILA S);
int desapilar(PILA S);
int elemTope(PILA S);

#endif
