#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void manejaMsg(int);
void agregarDato(COLA C);
COLA mezclaCola(COLA, COLA);
void mostrarCola(COLA);

void main(){
	COLA C1,C2,C3;
	C1 = crearCola();
	C2 = crearCola();
	C3 = crearCola();

	printf("Datos C1\n");
	agregarDato(C1);
	printf("Datos C2\n");
	agregarDato(C2);
	
	C3 = mezclaCola(C1,C2);
	
	printf("C1:\n");
	mostrarCola(C1);
	printf("C2:\n");
	mostrarCola(C2);
	printf("C3:\n");
	mostrarCola(C3);

	liberarCOLA(C1);
	liberarCOLA(C2);
	liberarCOLA(C3);
}

void agregarDato(COLA C){
    int opcion;
    int aux = 0;
    do
    {
        printf("Agrega el elemento a la cola:\n");
        scanf("%d",&aux);
        encolar(C,aux);
        printf("\nAgregar otro elemeto a la cola:\nNo -0-\t Si-1-\n\n"); 
        scanf("%d",&opcion);
    } while (opcion != 0);
}

COLA mezclaCola(COLA C1, COLA C2){
	COLA C3 = crearCola();
	Cola temp1 = *C1;
	Cola temp2 = *C2;
	int n;
	while(!es_vaciaCola(&temp1)&&!es_vaciaCola(&temp2)){
		encolar(C3, desencolar(&temp1));
		encolar(C3, desencolar(&temp2));
	}
	while(!es_vaciaCola(&temp1))
			encolar(C3, desencolar(&temp1));
		while(!es_vaciaCola(&temp2))
			encolar(C3, desencolar(&temp2));
	return C3;
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	while(!es_vaciaCola(&temp))
		printf("%d ",desencolar(&temp));
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}