#include <stdlib.h>
#include "cola.h"

void iniciaC(TCola *C){
    (*C).pri = (*C).ult = NULL;
}
int VaciaC(TCola C){
    return C.pri==NULL;
}

void poneC(TCola *C, TElementoC X){
    nodoC *aux;
    aux=(nodoC *)malloc(sizeof(nodoC));
    aux->dato=X;
    aux->sig=NULL;
    if((*C).pri==NULL)
        (*C).pri=aux;
    else
        (*C).ult->sig=aux;
    (*C).ult=aux;
}

void sacaC(TCola *C, TElementoC *X){
    nodoC *aux;
    if((*C).pri != NULL){
        aux = (*C).pri;
        *X = aux->dato;
        (*C).pri = (*C).pri->sig;
        if((*C).pri == NULL)
            (*C).ult = NULL;

        free(aux);
    }
}


