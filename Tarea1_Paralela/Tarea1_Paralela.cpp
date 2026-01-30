// Tarea1_Paralela.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    double start = omp_get_wtime();

    const int N = 1000;
    int arreglo1[N], arreglo2[N], arreglo3[N];
    int chunk = 100;
    srand(_time32(nullptr));

    // Inicializamos los arreglos
    for (int i = 0; i < N; i++) {
        arreglo1[i] = rand() % 100;
        arreglo2[i] = rand() % 100;
    }

    // Computamos la suma de cada celda de manera paralela con #pragma
#pragma omp parallel for \
    shared(arreglo1, arreglo2, arreglo3, chunk) \
    schedule(static, chunk)
    for (int i = 0; i < N; i++) {
        arreglo3[i] = arreglo1[i] + arreglo2[i];
    }

    cout << "Arreglo 1 - [0 - 9][990 - 1000]:\n";
    for (int i = 0; i < 10; i++)
        cout << arreglo1[i] << " | ";

    for (int i = 990; i < 1000; i++)
        cout << arreglo1[i] << " | ";
    cout << "\n\n";

    cout << "Arreglo 2 - [0 - 9][990 - 1000]:\n";
    for (int i = 0; i < 10; i++)
        cout << arreglo2[i] << " | ";
    for (int i = 990; i < 1000; i++)
        cout << arreglo2[i] << " | ";
    cout << "\n\n";

    cout << "[Resultado] Arreglo 3 - [0 - 9][990 - 1000]:\n";
    for (int i = 0; i < 10; i++)
        cout << arreglo3[i] << " | ";

    for (int i = 990; i < 1000; i++)
        cout << arreglo3[i] << " | ";
    cout << "\n";

    double end = omp_get_wtime();
    cout << "Tiempo transcurrido: " << end - start << endl;
    return 0;
}
