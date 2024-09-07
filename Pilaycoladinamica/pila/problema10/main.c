#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void agregarVehiculo(PILA);
void mostrarPila(PILA);
void sacarVehiculo(PILA);
void menu(PILA);

void main(){
    PILA P = crearPila();
    menu(P);
}
void menu(PILA S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Intorucir vehiculo \n2) Sacar vehiculo  \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                agregarVehiculo(S);
                break;
            case 2:
                sacarVehiculo(S);
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

void sacarVehiculo(PILA P){
    PILA aux = crearPila();
    PILA aux2 = crearPila();
    PILA aux3 = crearPila();
    Vehiculo a,m;
    int n;

    printf("\nIngresa la placa del vehiculo que quieres sacar: ");
    scanf("%d",&n);
    printf("\n");

    while(!es_vaciaPila(P)){
        a = desapilar(P);
        if(a.placa==n){
            apilar(aux2,a);
        }else{apilar(aux,a);}
    }

    while(!es_vaciaPila(aux)){
        m=desapilar(aux);
        apilar(aux3,m);
    }

    if(es_vaciaPila(aux2)){
        printf("\nEl vehiculo no existe:\n");
    }else{
        printf("\nDatos del vehiculo sacado:\n");
        mostrarPila(aux2);
    }

    printf("Vehiculos:\n");
    mostrarPila(aux3);
}

void agregarVehiculo(PILA pilaVehiculos) {
    char continuar;
    do {
        Vehiculo nuevoVehiculo;

        printf("\nIngrese la placa del vehiculo: ");
        scanf("%d", &nuevoVehiculo.placa);

        printf("Ingrese el estado del vehiculo (activo/inactivo): ");
        scanf("%s", nuevoVehiculo.estado);

        printf("Ingrese la marca del vehiculo: ");
        scanf("%s", nuevoVehiculo.marca);

        printf("Ingrese el modelo del vehiculo: ");
        scanf("%s", nuevoVehiculo.modelo);

        printf("Ingrese el año del vehiculo: ");
        scanf("%d", &nuevoVehiculo.año);

        printf("Ingrese el propietario del vehiculo: ");
        scanf("%s", nuevoVehiculo.propietario);

        apilar(pilaVehiculos, nuevoVehiculo);

        printf("Desea agregar otro vehiculo? (s/n): ");
        scanf(" %c", &continuar); 

    } while (continuar == 's' || continuar == 'S');
}

void mostrarPila(PILA pilaVehiculos) {
    if (es_vaciaPila(pilaVehiculos)) {
        printf("La pila de vehiculos esta vacia.\n");
        return;
    }

    printf("\nDatos de la pila de vehiculos:\n");

    while (!es_vaciaPila(pilaVehiculos)) {
        Vehiculo vehiculo = desapilar(pilaVehiculos);

        printf("\nPlaca: %d\n", vehiculo.placa);
        printf("Estado: %s\n", vehiculo.estado);
        printf("Marca: %s\n", vehiculo.marca);
        printf("Modelo: %s\n", vehiculo.modelo);
        printf("Ano: %d\n", vehiculo.año);
        printf("Propietario: %s\n", vehiculo.propietario);
        printf("------------------------\n");
    }
}
void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}
