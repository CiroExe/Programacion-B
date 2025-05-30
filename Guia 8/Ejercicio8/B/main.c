#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef unsigned int Digrafo[MAX][MAX];

int main()
{
    unsigned int n=4;
    Digrafo MA= {
        {0,1,1,0},
        {0,0,0,1},
        {1,1,0,0},
        {0,0,1,0}
    };

    printf("Vertice con mayor grado de entrada: %u", verticeMayorGradoEntrada(MA, 0, n)+1);
    return 0;
}

int calculaGradoEntrada(Digrafo MA, unsigned int v, unsigned int i, unsigned int n){

    if(i==n)
        return 0;
    else{
        if(MA[i][v]!=0)
            return 1+calculaGradoEntrada(MA,v,i+1,n);
        else
            return calculaGradoEntrada(MA,v,i+1,n);
    }
}

int verticeMayorGradoEntrada(Digrafo MA, unsigned int j, unsigned int n) {
    int Sig, gradoSig, gradoActual;
    if (j == n - 1) {
        return j;
    } else {
        Sig = verticeMayorGradoEntrada(MA, j + 1, n);
        gradoSig = calculaGradoEntrada(MA, Sig, 0, n);
        gradoActual = calculaGradoEntrada(MA, j, 0, n);

        if (gradoActual >= gradoSig)
            return j;
        else
            return Sig;
    }
}
