#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void CargaCola(TCola *C);
void MuestraCola(TCola *C);

int main()
{
    TCola C;

    printf("Cola Estatica\n");
    iniciaC(&C);
    CargaCola(&C);
    MuestraCola(&C);

    return 0;
}

void CargaCola(TCola *C){
    FILE *arch;
    int num;

    arch=fopen("numeros.txt","r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else{
        while (fscanf(arch,"%d",&num)== 1){
            poneC(C, num);
        }
        close(arch);
    }
}

void MuestraCola(TCola *C){
    TElementoC num;

    while (!VaciaC(*C)){
        sacaC(C, &num);
        printf("%d\n", num);
    }
}

