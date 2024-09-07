#include <stdio.h>
#include <stdlib.h>

typedef struct datos{
    char nombre[15];
    char ap_pater[15];
    int edad;
    char carrera[20];
}Datos;

typedef struct deportista{
    Datos pers;
    char deportes[30];
    int medallas;
}Deportista;

Deportista *crearEstructura();
void darDatos(Deportista *);
void promedio(Deportista *, int);   
void ingresar(Deportista *, int);
void mayor(Deportista *, int);

void main(){
    int n;
    Deportista *D = crearEstructura();
    printf("Ingresa la cantidad de personas que quieres ingresar: ");
    scanf("%d",&n);
    printf("\n");
    ingresar(D,n);
    promedio(D,n);
    mayor(D,n);
    
}

void mayor(Deportista *D, int n){
    int mayor = -1;
    int i;
    for(i=0; i<n; i++){
        if(D[i].medallas > mayor){
            mayor = D[i].medallas;
        }
    }
    printf("%s %s es el estudiante con el mayor numero de medallas y su carrera es %s", D[i].pers.nombre,D[i].pers.ap_pater,D[i].pers.carrera);
}

void promedio(Deportista *D, int n){
    int i, j, m, prom;
    int suma = 0;
    for(i=0; i<n; i++){
        m = D[i].medallas;
        suma += m;
    }
    prom = suma/n;
    printf("El promedio de medallas es: %d", prom);
    printf("\n");
    for(j=0; j<n; j++){
        if(D[j].medallas>prom){
            printf("%s tiene un numero de medallas mayor al promedio.\n",D[j].pers.nombre);
            printf("%s tiene %d medallas\n",D[j].pers.nombre,D[j].medallas);
        }
    }
}

void ingresar(Deportista *P, int n){
    int i;
    for(i=0; i<n; i++){
        printf("\nIngresa los datos de la persona %d\n",i+1);
        darDatos(&P[i]);
    }
}

void darDatos(Deportista *D){
    printf("Ingresa el nombre del Deportista: ");
    scanf("%s", D->pers.nombre);
    printf("Ingresa el apellido del deportista: ");
    scanf("%s",D->pers.ap_pater);
    printf("Ingresa la edad: ");
    scanf("%d",&D->pers.edad);
    printf("Ingresa la carrera del Deportista: ");
    scanf("%s", D->pers.carrera);
    printf("Ingresa el deporte que practica: ");
    scanf("%s", D->deportes);
    printf("Ingresa el numero de medallas que tiene: ");
    scanf("%d", &D->medallas);
    printf("\n");
}

Deportista * crearEstructura(){
    Deportista * nvo;
    nvo = (Deportista *)malloc(sizeof(Deportista));

    if(nvo==NULL){
        exit(0);
    }
    return nvo;
}