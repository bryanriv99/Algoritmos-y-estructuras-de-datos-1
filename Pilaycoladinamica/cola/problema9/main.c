#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void agregarCliente(COLA);
void mostrarCola(COLA);
void leerDatos(COLA);
void colaMAyores(COLA);
void manejaMsg(int);
void montoProm(COLA);
int tamCola(COLA);
void menu(COLA);

void main(){
    COLA C = crearCola();
    menu(C);
}

void menu(COLA S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Ingresar datos \n2) Depositos mayores \n3) Promedio de los montos \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                leerDatos(S);
                break;
            case 2:
                colaMAyores(S);
                break;
            case 3:
                montoProm(S);
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

void montoProm(COLA C){
    COLA aux = crearCola();
    aux = C;
    Cliente a;
    int j;
    int i=0;
    int div = 0;
    while(!es_vaciaCola(C)){
        a = desencolar(C);
        j = a.monto;
        i+=j;
        div++;
    }
    if(i>0){
        printf("\nEl monto promedio es %d\n",i/div);
    }else{printf("\nNo hay montos para promediar.\n");}
}

void colaMAyores(COLA C){
    COLA aux = crearCola();
    Cliente a;
    int n;
    printf("\nApartir de que monto te voy a mostrar: ");
    scanf("%d",&n);
    printf("\n");
    while(!es_vaciaCola(C)){
        a = desencolar(C);
        if(a.monto>=n){
            encolar(aux,a);
        }
    }
    if(es_vaciaCola(aux)){
        printf("NO hay montos mayores a la cantidad ingresada.\n");
    }else{
        printf("Montos mayores a %d:\n");
        mostrarCola(aux);
    }
}

void agregarCliente(COLA C) {
    Cliente a;

    // Solicitar información de la persona
    printf("\nIngrese el nomero de cliente: ");
    scanf("%d", &a.noCliente);
    printf("Ingrese el nombre: ");
    scanf("%s", a.nombre);

    printf("Ingrese el estado de la cuenta: ");
    scanf(" %d", &a.estado);

    printf("Ingrese el monto del deposito: ");
    scanf("%d", &a.monto);

    // Agregar a la persona a la cola
    encolar(C, a);
}

void leerDatos(COLA C){
    char opcion;
     printf("Desea agregar un cliente? (s/n): ");
        scanf(" %c", &opcion);
    while (opcion == 's' || opcion == 'S') {
        // Agregar cliente
        agregarCliente(C);

        // Preguntar si desea agregar otro cliente
        printf("Desea agregar otro cliente? (s/n): ");
        scanf(" %c", &opcion);

    } 
}

void mostrarCola(COLA C) {
    COLA temp = crearCola(); // Cola temporal para mantener la original sin cambios
    while (!es_vaciaCola(C)) {
        Cliente p = desencolar(C); // Desencolar la persona actual
        printf("\n");
        printf("Nombre: %s\n", p.nombre);
        printf("No. de cliente %d\n", p.noCliente);
        printf("Estado del cliente: %d\n", p.estado);
        printf("Monto del deposito: %d\n", p.monto);
        printf("\n");

        encolar(temp, p); // Volver a encolar la persona en la cola temporal
    }

    // Restaurar la cola original
    while (!es_vaciaCola(temp)) {
        Cliente p = desencolar(temp);
        encolar(C, p);
    }
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}

int tamCola(COLA C){
    int n;
    while(!es_vaciaCola(C)){
        desencolar(C);
        n++;
    }
    return n;
}