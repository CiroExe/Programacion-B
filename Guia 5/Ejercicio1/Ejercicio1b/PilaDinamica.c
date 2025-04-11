#include <stdlib.h>
#include "PilaDinamica.h"

void IniciaP(TPila *P)
{
    *P = NULL;
}

int VaciaP(TPila P)
{
    return (P == NULL);
}

void poneP(TPila *P, TElementoP dato)
{
    TPila N;
    N=(TPila)malloc(sizeof(nodoP));
    N ->elem = dato;
    N ->sig = *P;
    *P=N;
}

TElementoP consultaP(TPila P)
{
    return P -> elem;
}

void sacaP(TPila *P, TElementoP *dato)
{
    TPila N;
    if (*P != NULL)
    {
        N=*P;
        *dato = (*P) -> elem;
        *P = (*P) ->sig;
        free(N);
    }
}
