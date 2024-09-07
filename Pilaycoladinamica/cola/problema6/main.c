#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void agregarCliente(COLA);
void mostrarCola(COLA);
void leerDatos(COLA);
void asignaticket(Persona *);
void colanoColados(COLA);
void manejaMsg(int);

void main(){
    COLA C = crearCola();
    COLA aux = crearCola();
    Persona a;
    leerDatos(aux);

    while(!es_vaciaCola(aux)){
        a = desencolar(aux);
        asignaticket(&a);
        encolar(C,a);
    }
    colanoColados(C);
}

void colanoColados(COLA C){
    COLA ordenado = crearCola();
    COLA colados = crearCola();
    COLA C1 = crearCola();
    COLA C2 = crearCola();
    COLA C3 = crearCola();
    COLA C4 = crearCola();
    COLA C5 = crearCola();
    Persona p,o,a,b,c,d;

    while(!es_vaciaCola(C)){
        p=desencolar(C);
        if(p.ticket==1){
            if(p.atencion==5){
                encolar(C5,p);
            }
            if(p.atencion==4){
                encolar(C4,p);
            }
            if(p.atencion==3){
                encolar(C3,p);
            }
            if(p.atencion==2){
                encolar(C2,p);
            }
            if(p.atencion==1){
                encolar(C1,p);
            }
        }else{encolar(colados,p);}
    }

    while(!es_vaciaCola(C5)){
        o=desencolar(C5);
        encolar(ordenado,o);
    }
    while(!es_vaciaCola(C4)){
        a = desencolar(C4);
        encolar(ordenado,a);
    }
    while(!es_vaciaCola(C3)){
        b = desencolar(C3);
        encolar(ordenado,b);
    }
    while(!es_vaciaCola(C2)){
        c = desencolar(C2);
        encolar(ordenado,c);
    }
    while(!es_vaciaCola(C1)){
        d = desencolar(C1);
        encolar(ordenado,d);    
    }
    printf("\n");
    printf("Fila de los colados:\n");
    mostrarCola(ordenado);
    printf("\nFila de los *No colados*:\n");
    mostrarCola(colados);
}

void asignaticket(Persona *p){
    p->ticket = rand() %2;// genera un numero aleatorio de entre 0 y 1
    if(p->ticket==1){
        p->atencion = rand () %5 +1; // genera un numero aleatorio entre 1 y 5
    }
}

void agregarCliente(COLA C) {
    Persona a;

    // Solicitar información de la persona
    printf("Ingrese el nombre: ");
    scanf("%s", a.nombre);

    printf("Ingrese el sexo[M/F]: ");
    scanf(" %c", &a.sexo);

    printf("Ingrese la edad: ");
    scanf("%d", &a.edad);

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
        Persona p = desencolar(C); // Desencolar la persona actual
        printf("\n");
        printf("Nombre: %s\n", p.nombre);
        printf("Sexo: %c\n", p.sexo);
        printf("Edad: %d\n", p.edad);
        printf("Ticket: %d\n", p.ticket);
        printf("Atencion: %d\n", p.atencion);
        printf("\n");

        encolar(temp, p); // Volver a encolar la persona en la cola temporal
    }

    // Restaurar la cola original
    while (!es_vaciaCola(temp)) {
        Persona p = desencolar(temp);
        encolar(C, p);
    }
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}