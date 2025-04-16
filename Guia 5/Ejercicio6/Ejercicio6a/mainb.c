#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *);
void promedio (TPila *, float *);


int main()
{
    TPila P;
    int cont;

    iniciaP(&P);
    CargaPila(&P);

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

void promedio (TPila *P, float *promedio){
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


