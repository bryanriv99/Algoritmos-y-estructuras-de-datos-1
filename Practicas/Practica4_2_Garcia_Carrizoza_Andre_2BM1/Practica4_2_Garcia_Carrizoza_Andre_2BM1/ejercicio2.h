#ifndef  _pila_
#define  _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0

typedef struct{
   char pila[TAMPILA];
   int tope;
}Pila;

typedef Pila* PILA;


// operaciones
PILA crearPila();
void apilar(PILA, char);
int es_vaciaPila(PILA);
char desapilar(PILA);
char elemTope(PILA);


#endif

