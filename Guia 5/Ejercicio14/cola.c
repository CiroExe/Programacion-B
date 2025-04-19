#include "cola.h"
#include <stdlib.h>

void iniciaC(TCola *C){
    C->pri = NULL;
    C->ult = NULL;
}

void poneC(TCola *C, TElementoC dato){
    nodoC *auxC;

    auxC=(nodoC *)malloc(sizeof(nodoC));

    auxC->dato=dato;
    auxC->sig=NULL;

    if(C->pri == NULL)
        C->pri = auxC;
    else
        C->ult->sig= auxC;

    C->ult = auxC;
}

void sacaC(TCola *C, TElementoC *dato){
    nodoC *auxC;

    if (C->pri != NULL){
        auxC=C->pri;

        *dato=C->pri->dato;

        C->pri=auxC->sig;

        if (C->pri ==NULL)
            C->ult=NULL;

        free(auxC);
    }
}

int VaciaC(TCola C){
    return C.pri==NULL;
}
