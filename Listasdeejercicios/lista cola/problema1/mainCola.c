#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void menu(COLA);
void mostrarOpciones();
void manejaMsg(int);
COLA datosEntrada();
void agregarDato(COLA);
void numElementos(COLA);
void mostrarCola(COLA);

void main(){
	COLA C;
	C=datosEntrada();
	menu(C);
}

void menu(COLA C){
    int op;
    do{
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
			agregarDato(C);
            break;
        case 2:
			numElementos(C);
            break;
        case 3:
			mostrarCola(C);
            break;
        case 4:
            liberarCOLA(C);
            break;

        default:
            printf("¡Opcion no valida! Ingrese una opcion valida\n");
            break;
        }
    }while(op!=4);
}

void mostrarOpciones(){
    printf("\n\t\tColas\n\n");
    printf("1.- Introducir elementos a cola\n");
    printf("2.- Numero de elemntos de la cola\n");
    printf("3.- Imprimir elementos de la cola\n");
    printf("4.- Salir\n\n");
}

COLA datosEntrada(){
	COLA C = crearCola();
	int n;
    char m;
	printf("Ingrese los datos que desea agregar a la cola:\n");
	while (1){
		scanf("%d",&n);
		m = getchar();
		encolar(C, n);
		if (m =='\n')
			break;
	}
	return C;
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

void numElementos(COLA C){
	Cola temp = *C;
	int n=0;
	while(!es_vaciaCola(&temp)){
		n++;
		desencolar(&temp);
	}
	printf("Numero de elementos de la cola: %d\n",n);
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	printf("Imprimiendo Cola: \n");
	while(!es_vaciaCola(&temp))
		printf("%d ",desencolar(&temp));
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s", mensajes[msg] );
}