#ifndef _pila_
#define _pila_
#define TAMPILA 100
#define TRUE 1
#define FALSE 0


typedef struct{
	int edad;
	char nombre[30];
	char sexo[1];
	double calif;

}Datos;

typedef struct 
{
    int pil[TAMPILA];
    int Tope;
}Pil;

typedef Pil * PIL;

typedef struct{
	Datos pila[TAMPILA];
	int tope;
}Pila;


typedef Pila * PILA;


PILA crearPila(void);
void apilar(PILA S, Datos e);
int es_vaciaPila(PILA S);
Datos desapilar(PILA S);
Datos elemTope(PILA S);
PIL CrearPila(void);
void Apilar(PIL S, int e);
int es_vaciaPil(PIL S);
int Desapilar(PIL S);

#endif
