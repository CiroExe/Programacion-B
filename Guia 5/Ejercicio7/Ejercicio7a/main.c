#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void CargaPila(TPila *P);
void MuestraPilaRec(TPila *);

int main()
{
    TPila P;
    iniciaP(&P);

    CargaPila(&P);
    MuestraPilaRec(&P);

    return 0;
}

void CargaPila(TPila *P){
    FILE *arch;
    TElementoP car;


    arch=fopen("letras.txt","r");
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else{
        fscanf(arch,"%c",&car);
        while (!feof(arch)){
            poneP(P, car);
            fscanf(arch,"%c",&car);
        }
        fclose(arch);
    }
}

void MuestraPilaRec(TPila *P){
    TElementoP dato;

    if (!VaciaP(*P)){
        sacaP(P, &dato);
        printf("%c\n", dato);
        MuestraPilaRec(P);
        poneP(P, dato);
    }
}
