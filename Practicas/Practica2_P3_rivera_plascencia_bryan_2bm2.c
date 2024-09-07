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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Materia {
    char nombre[50];
    int nivel;
    float calificacion;
};


struct Info_tels {
    char movil[30];
    char casa[30];
    char oficina[30];
};


struct Estudiante {
    char nombre_apellido[100];
    int edad;
    struct Materia materia;
    struct Info_tels telefonos;
};


int solicitarNumeroEstudiantes();
void crearArregloEstudiantes(struct Estudiante **estudiantes, int N);
void ingresarDatosEstudiante(struct Estudiante *estudiantes, int indice);
void mostrarEstudiantesConNotaMayor(struct Estudiante *estudiantes, int N, float nota);
void liberarMemoria(struct Estudiante *estudiantes);

int main() {
    int N = solicitarNumeroEstudiantes();


    struct Estudiante *estudiantes = (struct Estudiante *)malloc(N * sizeof(struct Estudiante));
    if (estudiantes == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        ingresarDatosEstudiante(estudiantes, i);
    }

    mostrarEstudiantesConNotaMayor(estudiantes, N, 8.5);
    liberarMemoria(estudiantes);

    return 0;
}

int solicitarNumeroEstudiantes() {
    int N;
    printf("Ingrese la cantidad de estudiantes a registrar: ");
    scanf("%d", &N);
    return N;
}

void crearArregloEstudiantes(struct Estudiante **estudiantes, int N) {
    *estudiantes = (struct Estudiante *)malloc(N * sizeof(struct Estudiante));
    if (*estudiantes == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
}

void ingresarDatosEstudiante(struct Estudiante *estudiantes, int indice) {
    printf("\nIngrese los datos para el estudiante %d:\n", indice + 1);

    printf("Nombre y apellido: ");
    scanf(" %[^\n]s", estudiantes[indice].nombre_apellido);

    printf("Edad: ");
    scanf("%d", &estudiantes[indice].edad);

    printf("Nombre de la materia: ");
    scanf(" %[^\n]s", estudiantes[indice].materia.nombre);

    printf("Nivel de la materia: ");
    scanf("%d", &estudiantes[indice].materia.nivel);

    printf("Calificacion de la materia: ");
    scanf("%f", &estudiantes[indice].materia.calificacion);

    printf("Numero de movil: ");
    scanf(" %[^\n]s", estudiantes[indice].telefonos.movil);

    printf("Numero de casa: ");
    scanf(" %[^\n]s", estudiantes[indice].telefonos.casa);

    printf("Numero de oficina: ");
    scanf(" %[^\n]s", estudiantes[indice].telefonos.oficina);
}

void mostrarEstudiantesConNotaMayor(struct Estudiante *estudiantes, int N, float nota) {
    printf("\nEstudiantes con calificacion mayor a %.2f:\n", nota);
    int encontrado = 0;
    for (int i = 0; i < N; i++) {
        if (estudiantes[i].materia.calificacion > nota) {
            printf("Nombre y apellido: %s\n", estudiantes[i].nombre_apellido);
            printf("Numero de casa: %s\n", estudiantes[i].telefonos.casa);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron estudiantes con calificación mayor a %.2f.\n", nota);
    }
}

void liberarMemoria(struct Estudiante *estudiantes) {
    free(estudiantes);
}
