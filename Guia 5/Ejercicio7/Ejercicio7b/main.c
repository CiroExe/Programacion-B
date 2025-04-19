#include <stdio.h>
#include <stdlib.h>
#include "Punto3.h"
void CargaPila(TPila *P);
void MuestraP(TPila *, int);

int main()
{
    TElementoP dni;
    unsigned int n;
    TPila P;

    iniciaP(&P);

    CargaPila(&P);
    printf("Ingrese los ultimos votantes que desea mostrar\n");
    scanf("%u", &n);

    printf("Lista de votantes\n");
    MuestraP(&P,n);

    return 0;
}

void MuestraPManteniendo(TPila *P,int n){
    TElementoP dni;

    if (!VaciaP(P) && n>0 ){
        sacaP(P,&dni);
        MuestraP(P,N-1);
        poneP(P, dni);
        printf("%s\n", dni);
    }

}

void CargaPila(TPila *P){
    TElementoP dni;

    printf("Ingrese dni (999 para finalizar)\n");
    scanf("%s",dni);
    while (strcmp(dni,"999") != 0){
        poneP(&P, dni);
        printf("Ingrese dni (999 para finalizar)\n");
        scanf("%s",dni);
    }

}
