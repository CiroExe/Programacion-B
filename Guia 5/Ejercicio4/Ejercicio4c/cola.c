#include "cola.h"
#include <stdlib.h>

void iniciaC(TCola *C){
    C ->pri = NULL;
    C ->ult = NULL;
}

void poneC(TCola *C, TElementoC dato){
    nodo *auxC;

    auxC=(nodo *)malloc(sizeof(nodo));

    auxC -> dato = dato;
    auxC ->sig = NULL;

    if ((*C).pri != NULL)
        (*C).ult ->sig=auxC;
    else
        (*C).pri = auxC;

    (*C).ult = auxC;
}

void sacaC(TCola *C, TElementoC *dato){
    nodo *auxC;

    if ((*C).pri != NULL){
        auxC=(*C).pri;
        *dato = (*C).pri->dato ; // ó auxC -> dato
        (*C).pri = auxC ->sig;
        if ((*C).pri == NULL)
            (*C).ult = NULL;

        free(auxC);
    }
}

int VaciaC(TCola C){
    return C.pri == NULL;
}

TElementoC consultaC(TCola C){
    return C.ult -> dato;
}
