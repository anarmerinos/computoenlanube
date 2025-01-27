#include <iostream>
#include <omp.h>

#define N 1000       // Tamaño de los arreglos
#define CHUNK 100    // Tamaño de los pedazos para OpenMP
#define MOSTRAR 10   // Cantidad de elementos a mostrar

// Declaración de la función para imprimir un arreglo
void imprimeArreglo(float *d);

int main () {
    std::cout << "Sumando Arreglos en Paralelo\n";

    // Declaración de los arreglos
    float a[N], b[N], c[N];
    int i;

    // Inicialización de los arreglos a y b
    for (i = 0; i < N; i++) {
        a[i] = rand() % 100 + 10; // Números aleatorios entre 0 y 99
        b[i] = rand() % 100 * 5; // Números aleatorios entre 0 y 99
    }

    int pedazos = CHUNK;

    // Directiva OpenMP para paralelizar el bucle
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }

    // Imprimir los primeros 10 elementos de cada arreglo
    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

// Implementación de la función para imprimir un arreglo
void imprimeArreglo(float *d) {
    for (int x = 0; x < MOSTRAR; x++) {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}