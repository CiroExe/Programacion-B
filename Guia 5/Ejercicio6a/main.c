#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *);
void cuentaCeros(TPila *, int *);


int main()
{
    TPila P;
    int cont;

    iniciaP(&P);
    CargaPila(&P);
    cuentaCeros(&P, &cont);
    printf("Cantidad de ceros en la pila: %d", cont);

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

void cuentaCeros(TPila *P, int *cont){
    int num;

    while (!VaciaP(*P)){
        if (consultaP(*P) == 0)
            (*cont)++;
        sacaP(P, &num);
    }
}
