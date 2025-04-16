#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *);
void Max(TPila *, int *);
void Min(TPila *, int *);


int main()
{
    TPila P;
    int maximo=-9999, minimo=9999;

    iniciaP(&P);
    CargaPila(&P);
    Max(&P, &maximo);
    Min(&P, &minimo);

    printf("Maximo: %d\n", maximo);
    printf("Minimo: %d\n", minimo);

    return 0;
}

void CargaPila(TPila *P){
    int num;

    printf("Ingrese numero entero o 999 para finalizar\t");
    scanf("%d", &num);
    while(num != 999){
        poneP(P, num);
        printf("Ingrese numero entero o 999 para finalizar\t");
        scanf("%d", &num);
    }
}

void Max(TPila *P, int *maximo){
    int num, tope;
    TPila aux;


    while (!VaciaP(*P)){
        tope = consultaP(*P);
        if (tope > *maximo)
            *maximo = tope;
        sacaP(P, &num);
        poneP(&aux, num);
    }

    while (!VaciaP(aux)){
        sacaP(&aux, &num);
        poneP(P, num);
    }
}

void Min(TPila *P, int *minimo){
    int tope, num;
    TPila aux;


    while (!VaciaP(*P)){
        tope = consultaP(*P);
        if (tope < (*minimo))
            *minimo = tope;
        sacaP(P, &num);
        poneP(&aux, num);
    }

    while (!VaciaP(aux)){
        sacaP(&aux, &num);
        poneP(P, num);
    }
}
