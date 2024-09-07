#ifndef pilaDina
#define pilaDina

#define TRUE 1
#define FALSE 0

typedef struct {
    int dia;
    int mes;
    int año;
} Fecha;

typedef struct{
    int numero;
    char titular[30];
    char tramite[50];
    Fecha fecha;
}Expediente;

typedef struct Nodo_Pila {
    Expediente dato;
    struct Nodo_Pila *anterior;
} Nodo_Pila;

typedef struct {
    Nodo_Pila *tope;
} Pila;

typedef Pila *PILA;

PILA crearPila();
int es_vaciaPila(PILA S);
Nodo_Pila *crearNodoPila();
Expediente elemTope(PILA S);
void apilar(PILA S, Expediente e);
Expediente desapilar(PILA S);

#endif
