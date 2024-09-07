#include <stdio.h>

void test_leer() {
  char cadena[100];

  // Prueba 1: Cadena vacía
  printf("Prueba 1: Cadena vacía\n");
  leer(cadena);
  printf("Cadena leída: %s\n\n", cadena);

  // Prueba 2: Cadena con un solo carácter
  printf("Prueba 2: Cadena con un solo carácter\n");
  leer(cadena);
  printf("Cadena leída: %s\n\n", cadena);

  // Prueba 3: Cadena con varios caracteres
  printf("Prueba 3: Cadena con varios caracteres\n");
  leer(cadena);
  printf("Cadena leída: %s\n\n", cadena);
}

int main() {
  test_leer();
  return 0;
}