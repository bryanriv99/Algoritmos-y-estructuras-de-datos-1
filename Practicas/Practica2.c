/*Defina la estructura estudiante que contiene los siguientes elementos:
1.- nombre y apellido(cadena de caracteres
2.- Edad: entero
3.- matertia(estructura anidada estatica que contiene: nombre(cadena de caracteres, Nivel(entero) y calificacion (decimal)
4.- Telefonos( estructura anidada estatica vista en clase Info_tels)

REalizar un programa aplicado a la modularidad y programacion estructurada que por medio de un menu permita:
1.- Que solicite la cantidad  N de estudiantes a registrar.
2.- Que permita crear dinamicamente un arreglo de N estudiantes.
3.- solicite al usuario los datos de los estudiantes.
4.- Obtener y mostrar los nombre de los estudianrtes y su telefono de casa cuya nota sea mayor a 8.5 considerando el caso que no exista desplegar el mensaje.
5.- Salir del programa.
Despues de realizar alguna accion el programa debe regresar al menu y el usuario podra elegir otra accion hasta que decida salir del programa-
info tels:
movil(cadena de caracteres )
casa(cadena de caracteres)
oficina(cadena de caractere)*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char *nombre_apellido[100];
    int *edad;
    struct Materia *materia;
    struct Info_tels *telefono;
}Estudiante;

typedef struct{
    char nombre[100];
    int nivel;
    float calificacion;
}Materia;

typedef struct{
    char movil[30];
    char casa[30];
    char oficina[30];
}Info_tels;

int numAlumnos() {
    int N;
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &N);
    return N;
}
