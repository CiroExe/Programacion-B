#include <stdio.h>
#include <stdlib.h>
#include "Punto3.h"

int main()
{
    TElementoP dni;
    unsigned int N, cont;
    TPila P;

    iniciaP(&P);

    printf("Ingrese dni (999 para finalizar)\n");
    scanf("%s",dni);
    while (strcmp(dni,"999") != 0){
        poneP(&P, dni);
        printf("Ingrese dni (999 para finalizar)\n");
        scanf("%s",dni);
    }

    printf("Ingrese los ultimos votantes que desea mostrar\n");
    scanf("%u", &N);

    printf("Lista de votantes\n");
    cont=0;

    while(!VaciaP(P)){
        cont++;
        sacaP(&P, dni);
        if (cont <= N)
            printf("%s\n", dni);
    }

    return 0;
}
