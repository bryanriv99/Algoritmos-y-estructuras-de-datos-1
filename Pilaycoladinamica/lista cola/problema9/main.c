#include <stdio.h>
#include "cola.h"
#include <stdlib.h>

void LeerDatos(COLA clientes);
void colaMayores(COLA clientes, float cantidad);
float montoProm(COLA clientes);
void mostrarCola(COLA C);

int main() {
    COLA clientes = crearCola();

    LeerDatos(clientes);

    printf("\nClientes:\n");
    mostrarCola(clientes);

    float cantidad;
    printf("\nIngrese la cantidad para obtener depositos mayores: ");
    scanf("%f", &cantidad);
    colaMayores(clientes, cantidad);

    printf("\nMonto promedio de depósitos: %.2f\n", montoProm(clientes));

    liberarCOLA(clientes);

    return 0;
}

void LeerDatos(COLA clientes) {
    int opcion;
    do {
        Cliente nuevoCliente;
        printf("Ingrese el numero del cliente: ");
        scanf("%d", &nuevoCliente.numCliente);

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nuevoCliente.nombreCliente);

        printf("Ingrese el estado del cliente (1-activo, 0-inactivo): ");
        scanf("%d", &nuevoCliente.estado);

        printf("Ingrese el monto del deposito: ");
        scanf("%f", &nuevoCliente.deposito);

        encolar(clientes, nuevoCliente);
        
        printf("\n¿Desea ingresar otro cliente? (0-No, 1-Si): ");
        scanf("%d", &opcion);
    } while (opcion != 0);
}

void colaMayores(COLA clientes, float cantidad) {
    COLA clientesMayores = crearCola();
    while (!es_vaciaCola(clientes)) {
        Cliente cliente = desencolar(clientes);
        if (cliente.deposito > cantidad) {
            encolar(clientesMayores, cliente);
        }
    }

    printf("\nClientes con depositos mayores a %.2f:\n", cantidad);
    mostrarCola(clientesMayores);

    liberarCOLA(clientesMayores);
}

float montoProm(COLA clientes) {
    float totalDepositos = 0;
    int numClientes = 0;

    COLA clientesCopia = crearCola();
    while (!es_vaciaCola(clientes)) {
        Cliente cliente = desencolar(clientes);
        totalDepositos += cliente.deposito;
        encolar(clientesCopia, cliente);
        numClientes++;
    }

    // Restaurar la cola original
    while (!es_vaciaCola(clientesCopia)) {
        encolar(clientes, desencolar(clientesCopia));
    }

    if (numClientes == 0) {
        return 0.0; // Evitar la división por cero
    }

    return totalDepositos / numClientes;
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
    printf("%s\n", mensajes[msg] );
}
void mostrarCola(COLA C) {
    int i;
    if (es_vaciaCola(C)) {
        printf("La cola está vacía.\n");
        return;
    }

    printf("Contenido de la cola:\n");
    for (i = 0; i < C->tam; i++) {
        printf("Cliente %d: %s, Monto: %.2f\n", C->cola[(C->primero + i) % TAMCOLA].numCliente,
               C->cola[(C->primero + i) % TAMCOLA].nombreCliente,
               C->cola[(C->primero + i) % TAMCOLA].deposito);
    }
}
