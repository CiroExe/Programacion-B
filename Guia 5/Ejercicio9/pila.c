#include "pila.h"
#include <stdlib.h>

void iniciaP(TPila *P){
    *P = NULL;
}

void poneP(TPila *P, TElementoP elem){
    TPila aux;

    aux = (TPila)malloc(sizeof(nodo));

    aux -> elem = elem;

    aux -> sig = *P;

    *P = aux;
}

void sacaP(TPila *P, TElementoP *elem){
    TPila aux;

    if ((*P) != NULL){
        aux= *P;
        *elem = aux->elem;
        *P= aux->sig;
        free(aux);
    }
}

int VaciaP(TPila P){
    return P -> elem == NULL;
}
