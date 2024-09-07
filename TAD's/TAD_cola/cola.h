#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int cola[TAMCOLA];
    int primero, ultimo;
    int tam;
} Cola;

typedef Cola *COLA;

COLA crearCola();
int es_vaciaCola(COLA);
void encolar(COLA, int);
int desencolar(COLA);
int sig(int);
int primero(COLA);

#endif

