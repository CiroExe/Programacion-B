#include "cola.h"

void iniciaC(TCola *C){
    C->pri = -1;
    C->ult = -1;
}

void poneC(TCola *C, TElementoC dato){

    if ((*C).pri == -1){
        (*C).V[++(*C).pri] =dato;
        (*C).ult=0;
    }
    else
        if ((*C).ult != MAX-1)
            (*C).V[++(*C).ult]=dato;
}

void sacaC(TCola *C, TElementoC *dato){
    if ((*C).pri != -1){
        *dato = (*C).V[(*C).pri];
        if ((*C).pri == (*C).ult)
            iniciaC(C);
        else
            (*C).pri++;
    }
}

int VaciaC(TCola C){
    return C.pri== -1;
}

TElementoC consultaC(TCola C){
    return C.V[C.pri];
}
