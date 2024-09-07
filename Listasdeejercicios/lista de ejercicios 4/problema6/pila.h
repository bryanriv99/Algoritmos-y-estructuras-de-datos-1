#ifndef _pila_
#define _pila_
#define TAMPILA 25

typedef struct{
	char pila[TAMPILA];
	int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
void apilar(PILA S, char e[]);
int es_vaciaPila(PILA S);
char * desapilar(PILA S);
char * elemTope(PILA S);

#endif
