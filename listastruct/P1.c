#include <stdio.h>

typedef struct{
    int x;
    int y;
}PUNTO;

PUNTO *crearEstructura();
void solicitarDatos(PUNTO *);
void puntomedio(PUNTO *);
void distancia(PUNTO *);
void menu(PUNTO *);
void liberar(PUNTO *);

void main(){
    PUNTO *P = crearEstructura();
    solicitarDatos(P);
    menu(P);
}

void menu(PUNTO *S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Punto medio \n2) Distacia \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                puntomedio(S);
                break;
            case 2:
                distancia(S);
                break;
            case 0:
                respuesta = -1;
                break;
            default:
                printf("\nIntroduzca una opcion valida!: ");
                break;
        }
    }
}

void distancia(PUNTO *P){
    int n;
    n = P->y - P->x;
    printf("La distancia entre el punto *x* y *y* es: %d", n);
}

void puntomedio(PUNTO *P){
    int n,m;
    n = P->x + P->y;
    m = n/2;
    printf("El punto medio entre el *x* y *y* es: %d", m);
}

PUNTO * crearEstructura(){
    PUNTO * nvo;
    nvo = (PUNTO *)malloc(sizeof(PUNTO));

    if(nvo==NULL){
        exit(0);
    }
}

void solicitarDatos(PUNTO * P){
    printf("Dame el valor del punto x: ");
    scanf("%d", &P->x);
    printf("\n");
    printf("Dame el valor de y: ");
    scanf("%d",&P->y);
}

void liberar(PUNTO *P){
    free(P);
}