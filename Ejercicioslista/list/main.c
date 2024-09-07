#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void llenar(LISTA *AP);
void liberarLista(LISTA L);
void manejaMsg(int n);
TNodoPaciente *listaPacDiag(TNodoMedico *, char *, char *);

int main() {
    LISTA L = crearLista();
    char col [10], diag[100];
    llenar(&L);
    printf("\n\nIngresa el colegiado del Medico: ");
    scanf("%s",col);
    printf("\n");
    printf("Ingresa el diagnostico: ");
    scanf("%s",diag);
    listaPacDiag(&(L->dato),diag,col);
    liberarLista(L);
    return 0;
}

void llenar(LISTA *AP) {
    int numMedicos;
    printf("Digite el numero de medicos: ");
    scanf("%d", &numMedicos);

    for (int i = 0; i < numMedicos; i++) {
        TNodoMedico medico;
        printf("Digite el código de colegiado del medico %d: ", i + 1);
        scanf("%s", medico.infoMedico.codColegiado);

        printf("Digite el nombre del medico %d: ", i + 1);
        scanf("%s", medico.infoMedico.nombre);

        // Puedes solicitar más información del médico si es necesario

        medico.listaPaci = NULL;  // Inicializa la lista de pacientes del médico como vacía

        int numPacientes;
        printf("Digite el numero de pacientes para el medico %d: ", i + 1);
        scanf("%d", &numPacientes);

        for (int j = 0; j < numPacientes; j++) {
            TNodoPaciente *paciente = (TNodoPaciente *)malloc(sizeof(TNodoPaciente));
            // Solicita información del paciente
            printf("Digite el número de historia del paciente %d: ", j + 1);
            scanf("%s", paciente->infoPaci.NumHistoria);

            printf("Digite el nombre del paciente %d: ", j + 1);
            scanf("%s", paciente->infoPaci.nombre);

            printf("Digite el diagnóstico del paciente %d: ", j + 1);
            scanf("%s", paciente->infoPaci.diagnostico);
            // Solicita más información del paciente si es necesario
            // ...

            // Agrega el paciente a la lista del médico
            paciente->sigPaciente = medico.listaPaci;
            medico.listaPaci = paciente;
        }

        // Inserta el médico en la lista general
        *AP = insertar(*AP, medico);
    }
}


void liberarLista(LISTA L){
    free(L);
    manejaMsg(2);
}

TNodoPaciente *listaPacDiag(TNodoMedico *clinica, char *diagnostico, char *codColegiado) {
    TNodoMedico *actualMedico = clinica;
    LISTA temp = crearLista();
    while (actualMedico != NULL) {
        // Compara el código de colegiado
        if (strcmp(actualMedico->infoMedico.codColegiado, codColegiado) == 0) {
            TNodoMedico *actualPaciente = &actualMedico->listaPaci;

            while (actualPaciente != NULL) {
                // Compara el diagnóstico
                if (strcmp(actualPaciente->listaPaci->infoPaci.diagnostico, diagnostico) == 0) {
                    // Aquí puedes realizar las acciones que necesites con el paciente encontrado
                    insertar(temp,*actualPaciente);
                    return &actualPaciente;
                }

                actualPaciente = &actualPaciente->listaPaci->sigPaciente;
            }
        }

        actualMedico = actualMedico->sigMedico;
    }

}

void manejaMsg(int n) {
    char *errores[] = {"No hay memoria disponible\n", "La lista esta vacia\n", "Memoria liberada\n"};
    printf("%s", errores[n]);
}
