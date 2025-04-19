#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *);
void TransformaPila(TPila *);
void MuestraP(TPila *);

int main()
{
    TPila P;
    iniciaP(&P);
    CargaPila(&P);
    TransformaPila(&P);
    MuestraP(&P);

    return 0;
}

void CargaPila(TPila *P){
    TElementoP dato;
    unsigned int i, n;

    printf("Ingrese cantidad de elementos que contendra la pila: \n");
    scanf("%u", &n);

    for (i=0; i<n; i++){
        printf("Ingrese elemento %u\t", i+1);
        scanf("%d", &dato);
        poneP(P, dato);
    }
}

void TransformaPila(TPila *P){
    TElementoP dato,datoTrans;

    if (!VaciaP(*P)){
        sacaP(P, &dato);
        printf("%d\n", dato);
        TransformaPila(P);
        datoTrans = dato * -1;
        printf("Dato transformado ->\t%d\n", datoTrans);
        poneP(P, datoTrans);
    }
}

void MuestraP(TPila *P){
    TElementoP dato;

    while (!VaciaP(*P)){
        sacaP(P, &dato);
        printf("%d\n", dato);
    }
}
