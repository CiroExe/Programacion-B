#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef int Grafo[MAX][MAX];

unsigned int calculaGrado(Grafo, unsigned int, unsigned int, int);
void generaVec(Grafo, unsigned int, unsigned int, unsigned int[]);
void muestraVec(unsigned int[], unsigned int);

int main() {
    unsigned int n = 3;
    unsigned int vGr[MAX];

    Grafo MA = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    generaVec(MA, 0, n, vGr);
    muestraVec(vGr, n);
    return 0;
}

unsigned int calculaGrado(Grafo MA, unsigned int n, unsigned int j, int v) {
    if (j == n)
        return 0;
    else {
        if (MA[v][j] != 0) {
            if (v == j)
                return 2 + calculaGrado(MA, n, j + 1, v);
            else
                return 1 + calculaGrado(MA, n, j + 1, v);
        } else
            return calculaGrado(MA, n, j + 1, v);
    }
}

void generaVec(Grafo MA, unsigned int i, unsigned int n, unsigned int vGr[]) {
    if (i < n) {
        vGr[i] = calculaGrado(MA, n, 0, i);
        generaVec(MA, i + 1, n, vGr);
    }
}

void muestraVec(unsigned int vGr[], unsigned int n) {
    for (int i = 0; i < n; i++)
        printf("Grado del vértice %d: %u\n", i, vGr[i]);
}

