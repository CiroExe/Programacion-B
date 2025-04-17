#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void iniciaC(TCola *C){
    C -> pri = NULL;
    C -> ult = NULL;
}

void poneC(TCola *C, TElementoC empleado){
    nodo *aux;

    aux = (nodo *)malloc(sizeof(nodo));

    aux -> empleado = empleado;
    aux ->sig = NULL;

   if (C -> pri == NULL)
        C -> pri = aux;
   else
        C -> ult -> sig = aux;

   C ->ult = aux;
}

void sacaC(TCola *C, TElementoC *empleado){
    nodo *aux;

    if (C->pri != NULL){
        aux=C->pri;
        *empleado = aux ->empleado;
        C->pri=aux -> sig;
        if (C -> pri == NULL)
            C ->ult = NULL;
        free(aux);
    }
}

int VaciaC(TCola C){
    return C.pri == NULL;
}

TElementoC consultaC(TCola C){
    return C.pri ->empleado;
}
