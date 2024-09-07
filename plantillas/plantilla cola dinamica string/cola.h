#ifndef _colaDina_h_
#define _colaDina_h_

#define TRUE 1
#define FALSE 0

typedef struct Nodo_Cola {
    char *dato;  // Cambié el tipo de dato a char*
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
char* primero(COLA);  // Cambié el tipo de retorno a char*
void encolar(COLA, char*);  // Cambié el tipo de parámetro a char*
char* desencolar(COLA);  // Cambié el tipo de retorno y de la función a char*

#endif
