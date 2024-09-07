#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int edad;
    char nombre[30];
    char dir[100];
    int tel;
} PERSONA;

void darDatos();
void ingresar(PERSONA *);
void ordenar(PERSONA *, int);

int main() {
    darDatos();
    return 0;
}

void ordenar(PERSONA *P, int n) {
    // Implementa un algoritmo de ordenamiento (puedes usar bubble sort por simplicidad)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].edad < P[j + 1].edad) {
                // Intercambia las estructuras si están en el orden incorrecto
                PERSONA temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }
}

void darDatos() {
    int n;
    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &n);

    // Crea el arreglo dinámicamente
    PERSONA *P = (PERSONA *)malloc(n * sizeof(PERSONA));
    if (P == NULL) {
        exit(0);
    }

    // Ingresa los datos
    for (int i = 0; i < n; i++) {
        printf("Ingresa los datos de la persona %d:\n", i + 1);
        ingresar(&P[i]);
    }

    // Ordena el arreglo por edad de mayor a menor
    ordenar(P, n);

    // Muestra los datos ordenados
    printf("\nDatos ordenados por edad de mayor a menor:\n");
    for (int i = 0; i < n; i++) {
        printf("Edad: %d, Nombre: %s, Direccion: %s, Telefono: %d\n", P[i].edad, P[i].nombre, P[i].dir, P[i].tel);
    }

    // Libera la memoria
    free(P);
}

void ingresar(PERSONA *P) {
    printf("Ingresa la edad de la persona: ");
    scanf("%d", &P->edad);
    printf("Ingresa el nombre de la persona: ");
    scanf("%s", P->nombre);
    printf("Ingresa la direccion de la persona: ");
    scanf("%s", P->dir);
    printf("Ingresa el telefono de la persona: ");
    scanf("%d", &P->tel);
    printf("\n");
}
