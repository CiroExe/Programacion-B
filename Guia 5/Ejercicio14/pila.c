#include "pila.h"
#include <stdlib.h>

void iniciaP(TPila *P){
    *P = NULL;
}

void poneP(TPila *P, TElementoP dato){
    TPila auxP;

    auxP=(TPila)malloc(sizeof(nodo));

    auxP ->dato =dato;

    auxP -> sig = *P;

    *P = auxP;
}

void sacaP(TPila *P, TElementoP *dato){
    TPila auxP;

    if (*P != NULL){
        auxP=*P;

        *dato = auxP->dato;

        *P = auxP -> sig;

        free(auxP);
    }
}

int VaciaP(TPila P){
    return P == NULL;
}
