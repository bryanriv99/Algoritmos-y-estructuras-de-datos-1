// Main.c

#include <stdio.h>
#include "cola.h"
#include <stdlib.h>

void agregarDato(COLA C);
void asignaTicket(Persona *p);
COLA colaNoColados(COLA C);
void manejaMsg(int);
void mostrarCola(COLA C, int mostrarConTicket);
void leerDatos(COLA);
int main() {
    COLA filaColados = crearCola();
    COLA filaNoColados = crearCola();

    leerDatos(filaColados);

    while (!es_vaciaCola(filaColados)) {
        Persona persona = desencolar(filaColados);
        asignaTicket(&persona);
        encolar(filaNoColados, persona);
    }

    // Ordenar la cola de No colados por número de atención
    filaNoColados = colaNoColados(filaNoColados);

 

    // Mostrar la información de la fila de No colados
    printf("\nFila de No Colados:\n");
    mostrarCola(filaNoColados, 1);
    printf("\nFila de Colados:\n");
    mostrarCola(filaNoColados, 0);

    liberarCOLA(filaColados);
    liberarCOLA(filaNoColados);

    return 0;
}

void leerDatos(COLA C){
    char continuar;
    do {
        agregarDato(C);
        printf("Desea formar a otra persona? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');
}

void agregarDato(COLA C) {
    Persona nuevaPersona;
    printf("Nombre: ");
    scanf("%s", nuevaPersona.nombre);
    printf("Sexo (M/F): ");
    scanf(" %c", &nuevaPersona.sexo);
    printf("Edad: ");
    scanf("%d", &nuevaPersona.edad);
    encolar(C, nuevaPersona);
}

void asignaTicket(Persona *p) {
    p->ticket = rand() % 2; // 0-No, 1-Si
    if (p->ticket == 1) {
        p->atencion = rand() % 5 + 1; // Número de atención (1-5)
    }
}

COLA colaNoColados(COLA C) {
    COLA colaOrdenada = crearCola();
    COLA colas[5];
    for (int i = 0; i < 5; i++) {
        colas[i] = crearCola();
    }

    while (!es_vaciaCola(C)) {
        Persona persona = desencolar(C);
        if (persona.ticket == 1) {
            encolar(colas[persona.atencion - 1], persona);
        } else {
            encolar(colaOrdenada, persona);
        }
    }

    // En este punto, colas[4] contendrá las personas con atención 5, colas[3] las de atención 4, y así sucesivamente.

    // Se agrega la lógica para encolar de forma prioritaria según el número de atención
    for (int i = 4; i >= 0; i--) {
        while (!es_vaciaCola(colas[i])) {
            encolar(colaOrdenada, desencolar(colas[i]));
        }
    }

    // Liberar colas temporales
    for (int i = 0; i < 5; i++) {
        liberarCOLA(colas[i]);
    }

    return colaOrdenada;
}

void mostrarCola(COLA C, int mostrarConTicket) {
    for (int i = C->primero; i != C->ultimo; i = (i + 1) % TAMCOLA) {
        Persona persona = C->cola[i];
        if ((mostrarConTicket && persona.ticket == 1) || (!mostrarConTicket && persona.ticket == 0)) {
            printf("Nombre: %s, Sexo: %c, Edad: %d, Ticket: %d, Atencion: %d\n",
                   persona.nombre, persona.sexo, persona.edad, persona.ticket, persona.atencion);
        }
    }
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}