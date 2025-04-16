#include <stdio.h>
#include <stdlib.h>
#include "PilaEstatica.h"

void iniciaP(TPila *P)
{
    (*P).tope = -1;
}

void poneP(TPila *P, TElementoP car)
{
    if ((*P).tope != MAX-1)
        (*P).C[++(*P).tope]= car;
}

void sacaP(TPila *P, TElementoP *car)
{
    if ((*P).tope != -1)
        *car = (*P).C[(*P).tope--];

}

int VaciaP(TPila P)
{
    return P.tope==-1;
}
