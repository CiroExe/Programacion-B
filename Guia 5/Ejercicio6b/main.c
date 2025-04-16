#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *);
void prom(TPila *, float *);


int main()
{
    TPila P;
    float promedio;

    iniciaP(&P);
    CargaPila(&P);
    prom(&P, &promedio);
    printf("Promedio de los elementos de la pila: %.2f", promedio);

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

void prom(TPila *P, float *promedio){
    TPila aux;
    int num, acum=0, cont=0;

    while (!VaciaP(*P)){
        sacaP(P,&num);
        poneP(&aux, num);
        cont++;
        acum += num;
    }

    while (!VaciaP(aux)){
        sacaP(&aux, &num);
        poneP(P, num);
    }
    *promedio = (float)acum / cont;
}


