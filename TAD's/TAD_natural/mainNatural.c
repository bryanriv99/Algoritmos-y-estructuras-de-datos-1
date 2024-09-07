#include "natural.h"
int main() {
    // Ejemplo de uso:
    NATURAL n1 = crearNatural(5);
    NATURAL n2 = crearNatural(10);

    printf("n1 es cero: %s\n", esCero(n1) ? "Verdadero" : "Falso");
    printf("n2 es cero: %s\n", esCero(n2) ? "Verdadero" : "Falso");

    printf("Sucesor de n1: %d\n", sucesor(n1)->valor);
    printf("Sucesor de n2: %d\n", sucesor(n2)->valor);

    printf("n1 es menor que n2: %s\n", esMenor(n1, n2) ? "Verdadero" : "Falso");
    printf("n1 es menor o igual que n2: %s\n", esMenorIgual(n1, n2) ? "Verdadero" : "Falso");
    printf("n1 es mayor que n2: %s\n", esMayor(n1, n2) ? "Verdadero" : "Falso");
    printf("n1 es mayor o igual que n2: %s\n", esMayorIgual(n1, n2) ? "Verdadero" : "Falso");

    printf("Predecesor de n1: %d\n", predecesor(n1)->valor);
    printf("Predecesor de n2: %d\n", predecesor(n2)->valor);

    return 0;
}
