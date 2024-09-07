

#include "Pilas.h"

void menu(PILA);

void anadirElemento(PILA);
PILA datosEntrada(PILA S);
PILA copiarPila(PILA P);
PILA invertirPila(PILA);
void imprimirElementos(PILA);
char *crearArrChar();
void liberarCanasta(PILA);

int main(){

    PILA pueblos = crearPila();
    datosEntrada(pueblos);
    PILA copia = copiarPila(pueblos);
    PILA regreso = invertirPila(copia);
    imprimirElementos(pueblos);
    imprimirElementos(regreso);
    liberarCanasta(pueblos);
    return 0;
}

PILA datosEntrada(PILA S){
	char elem[30];
	char opcion;

	printf("Ingresa los datos de los pueblos visitados\n");
	do{
        
		printf("Ingrese el nombre del pueblo:\n");
		 scanf("%[^\n]",elem);
		apilar(S, elem);
		printf("Quiere ingresar otro dato? (S/N)\n");
		scanf(" %c", &opcion);
        getchar();
	}while(opcion != 'N');

	return S;
}

/*void anadirElemento(PILA P){
    char *elemento = crearArrChar();
    printf("\n\n\tIngresa el objeto a anadir: ");
    scanf("%s",elemento);
    apilar(P,elemento);
}*/


void imprimirElementos(PILA P){
    char *c;
    int aux = 0;
    PILA tmp = crearPila();

    while(!(es_vaciaPila(P))){
        apilar(tmp,desapilar(P));
    }
    printf("\nEn la canasta tenemos: ");

    while(!(es_vaciaPila(tmp))){
        c = desapilar(tmp);
        aux++;
        printf("\n\t%d. %s.",aux,c);
        apilar(P,c);
    }
    printf("\n");
    liberarPilaTmp(tmp);
}

char *crearArrChar(){
    char *ap = (char*)malloc(sizeof(char)*25);
    if(ap == NULL){
        manejaError(2);
        exit(-1);
    }
    return ap;
}

PILA viajeIda(PILA S){
    PILA p=crearPila();
     while(!es_vaciaPila(S)){
       apilar(p,desapilar(S));   
     }
     return p;
}

PILA copiarPila(PILA P){
    char *aux = crearArrChar();
    PILA C = crearPila();
    PILA tmp = crearPila();
    while(!(es_vaciaPila(P))) {
        apilar(tmp,desapilar(P));
    }

    while(!(es_vaciaPila(tmp))){
        aux = desapilar(tmp);
        apilar(C, aux);
        apilar(P, aux);
    }
    liberarPilaTmp(tmp);
    printf("\nLa pila ha sido copiada con exito...\n");
    return C;
}

PILA invertirPila(PILA P){
    PILA tmp = crearPila();

    while(!es_vaciaPila(P)){
        apilar(tmp, desapilar(P));
    }
    return tmp;
}

void liberarCanasta(PILA ap){
    free(ap);
}
