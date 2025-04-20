#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void iniciaP(TPila *P){
    P->tope = -1;
}

void poneP(TPila *P, TElementoP competidor){
    if (P->tope != MAX-1)
        strcpy(P->competidores[++(P->tope)], competidor);
}

void sacaP(TPila *P, TElementoP *competidor){

    if (P->tope != -1)
        strcpy(competidor, P->competidores[(P->tope)--]);
}

int VaciaP(TPila P){
    return P.tope == -1;
}
