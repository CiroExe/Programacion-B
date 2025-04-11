#include "Pila Estatica.h"
#include <stdio.h>

void IniciaP(TPila *P)
{
    (*P).tope = -1;
}

void poneP(TPila *P, TElementoP dato)
{
    if ((*P).tope != MAX-1)
        (*P).A[++(*P).tope]=dato;
    printf("Se ingreso correctamente el elemento %d\n", dato);
}

/*void sacaP(TPila *P, TElemento *dato)
{
    if ((*P).tope != -1)
    {
        *dato = (*P).A[(*P).tope];
        (*P).tope -= 1;
    }
} */

void sacaP(TPila *P, TElementoP *dato)
{
    if ((*P).tope != -1)
    {
        *dato = (*P).A[(*P).tope--];
    }
    printf("%d\t", *dato);
}

TElementoP consultaP(TPila P)
{
    return P.A[P.tope]; //Devuelvo el primero en la pila (el ultimo que se ingresó)
}

int VaciaP(TPila P)
{
    return (P.tope == -1);
}
