#include "PilaDinamica.h"
#include <stdlib.h>

void iniciaP(TPila *P){
    *P = NULL;
}

void poneP(TPila *P, TElementoP car){
    TPila aux;

    aux=(nodo *)malloc(sizeof(nodo));

    aux -> dato = car;
    aux -> sig = *P;
    *P = aux;
}

void sacaP(TPila *P, TElementoP *car){
    TPila aux;

    if ((*P) != NULL) {
        aux = *P;
        *car = aux ->dato;
        *P = (*P) -> sig;
        free(aux);
    }
}

int VaciaP(TPila P){
    return (P == NULL);
}
