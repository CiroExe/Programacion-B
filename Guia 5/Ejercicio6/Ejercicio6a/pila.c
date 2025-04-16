#include "pila.h"
#include <stdlib.h>

void iniciaP(TPila *P){
    *P = NULL;
}

void poneP(TPila *P, TElementoP dato){
    TPila aux;

    aux=(TPila)malloc(sizeof(TPila));

    aux -> dato =dato;

    aux -> sig = (*P);

    *P = aux;
}

void sacaP(TPila *P, TElementoP *dato){
    TPila aux;

    if (*P != NULL){
        aux = *P;
        *dato = aux -> dato;
        *P = aux -> sig;
        free(aux);
    }
}

int VaciaP(TPila P){
    return P == NULL;
}

TElementoP consultaP(TPila P){
    return P -> dato;
}
