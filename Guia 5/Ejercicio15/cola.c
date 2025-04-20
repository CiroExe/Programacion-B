#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void iniciaC(TCola *C){
    C->pri=C->ult=-1;
}

void poneC(TCola *C, TElementoC competidor){

    if (C->ult != MAX-1){ //no llena
        if (C->pri == -1)
           C->pri=0;

        C->competidores[++((*C).ult)]=competidor;

    }
}

void sacaC(TCola *C, TElementoC *competidor){

    if (C->pri != -1){
        *competidor = C->competidores[((*C).pri)];
        if (C->pri == C->ult)
            iniciaC(C);
        else
            C->pri+=1;
    }
}

int VaciaC(TCola C){
    return C.pri == -1;
}
