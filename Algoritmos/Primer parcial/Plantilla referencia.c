#include<stdio.h>

typedef struct{
    char nombre [30];
    int edad;
    float peso;
}Persona;

Persona darDatos(Persona);
void mostar(Persona);

void main(){
    Persona pers1;

    pers1=darDatos(pers1);
    mostrar(pers1);
}
Persona darDatos(Persona pers1){
    printf("Introduzca el nombre\n");
    scanf("%[^\n]",pers1.nombre);
    printf("Introduzca edad\n");
    scanf("%d",&pers1.edad);
    printf("Introduzca el peso\n");
    scanf("%f",&pers1.peso);
    return pers1;
}
void mostrar(Persona pers1){
    printf("\nNombre: %s",pers1.nombre);
    printf("\nEdad: %d",pers1.edad);
    printf("\nPrecio: $%.2f",pers1.peso);
}
//balanza de comprobacion
