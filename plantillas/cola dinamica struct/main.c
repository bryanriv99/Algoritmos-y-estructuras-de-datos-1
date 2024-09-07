#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void agregarCliente(COLA);
void mostrarCola(COLA);
void datosEntrada(COLA);

void main(){

}
void agregarCliente(COLA C) {
    Cliente nuevoCliente;

    // Solicitar información del nuevo cliente
    printf("Ingrese el número del cliente: ");
    scanf("%d", &nuevoCliente.numCliente);

    printf("Ingrese el nombre del cliente: ");
    scanf("%s", nuevoCliente.nombreCliente);

    printf("Ingrese el estado del cliente: ");
    scanf("%d", &nuevoCliente.estado);

    printf("Ingrese el depósito del cliente: ");
    scanf("%f", &nuevoCliente.deposito);

    // Agregar el cliente a la cola
    encolar(C, nuevoCliente);
}

void datosEntrada(COLA C){
    char opcion;
    do {
        // Agregar cliente
        agregarCliente(C);

        // Preguntar si desea agregar otro cliente
        printf("¿Desea agregar otro cliente? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');
}

void mostrarCola(COLA C) {
    if (es_vaciaCola(C)) {
        printf("La cola está vacía.\n");
        return;
    }

    COLA copiaCola = crearCola(); // Crear una copia de la cola para no modificar la original

    while (!es_vaciaCola(C)) {
        Cliente cliente = primero(C);
        printf("Número del cliente: %d\n", cliente.numCliente);
        printf("Nombre del cliente: %s\n", cliente.nombreCliente);
        printf("Estado del cliente: %d\n", cliente.estado);
        printf("Depósito del cliente: %.2f\n", cliente.deposito);
        printf("\n");

        encolar(copiaCola, desencolar(C)); // Mover el cliente a la copia de la cola
    }

    // Restaurar la cola original
    while (!es_vaciaCola(copiaCola)) {
        encolar(C, desencolar(copiaCola));
    }

    liberarCOLA(copiaCola); // Liberar la memoria de la copia de la cola
}