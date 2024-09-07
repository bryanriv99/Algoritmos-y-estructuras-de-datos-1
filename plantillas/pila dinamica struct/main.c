#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void agregarVehiculo(PILA);
void mostrarPila(PILA);

void main(){

}

void agregarVehiculo(PILA pilaVehiculos) {
    char continuar;
    do {
        Vehiculo nuevoVehiculo;

        printf("Ingrese la placa del vehículo: ");
        scanf("%d", &nuevoVehiculo.placa);

        printf("Ingrese el estado del vehículo (activo/inactivo): ");
        scanf("%s", nuevoVehiculo.estado);

        printf("Ingrese la marca del vehículo: ");
        scanf("%s", nuevoVehiculo.marca);

        printf("Ingrese el modelo del vehículo: ");
        scanf("%s", nuevoVehiculo.modelo);

        printf("Ingrese el año del vehículo: ");
        scanf("%d", &nuevoVehiculo.año);

        printf("Ingrese el propietario del vehículo: ");
        scanf("%s", nuevoVehiculo.propietario);

        apilar(pilaVehiculos, nuevoVehiculo);

        printf("¿Desea agregar otro vehículo? (s/n): ");
        scanf(" %c", &continuar); // Espacio antes de %c para consumir el salto de línea anterior

    } while (continuar == 's' || continuar == 'S');
}

void mostrarPila(PILA pilaVehiculos) {
    if (es_vaciaPila(pilaVehiculos)) {
        printf("La pila de vehículos está vacía.\n");
        return;
    }

    printf("Datos de la pila de vehículos:\n");

    while (!es_vaciaPila(pilaVehiculos)) {
        Vehiculo vehiculo = desapilar(pilaVehiculos);

        printf("Placa: %d\n", vehiculo.placa);
        printf("Estado: %s\n", vehiculo.estado);
        printf("Marca: %s\n", vehiculo.marca);
        printf("Modelo: %s\n", vehiculo.modelo);
        printf("Año: %d\n", vehiculo.año);
        printf("Propietario: %s\n", vehiculo.propietario);
        printf("------------------------\n");
    }
}