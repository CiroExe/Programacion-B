#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void iniciaP(TPila *P){
    (*P).tope=-1;
}

void poneP(TPila *P, TElementoP dni){
    if ((*P).tope != MAX-1)
        strcpy((*P).V[++((*P).tope)], dni);
}

void sacaP(TPila *P, TElementoP *dni){
    if ((*P).tope != -1)
        strcpy(dni, (*P).V[(*P).tope--]);
}

TElementoP *consultaP(TPila P){
    if (P.tope != -1)
        return P.V[P.tope];
}

int VaciaP(TPila P){
    return P.tope == -1;
}
