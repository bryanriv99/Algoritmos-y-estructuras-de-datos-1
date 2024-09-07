#ifndef _cola_
#define _cola_
#define TAMCOLA 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int numCliente;
    char nombreCliente[50];
    int estado;
    float deposito;
} Cliente;

typedef struct {
    Cliente cola[TAMCOLA];
    int primero, ultimo;
    int tam;
} Cola;

typedef Cola *COLA;

COLA crearCola();
int es_vaciaCola(COLA C);
void encolar(COLA C, Cliente cliente);
Cliente desencolar(COLA C);
Cliente primero(COLA C);
void liberarCOLA(COLA C);
void manejaMsg(int msg);

#endif
