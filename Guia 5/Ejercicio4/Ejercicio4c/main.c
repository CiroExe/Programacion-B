#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void CargaCola(TCola *C);
void MuestraColaSinPerder(TCola *C);

int main()
{
    TCola C;

    CargaCola(&C);
    MuestraColaSinPerder(&C);

    return 0;
}

void CargaCola(TCola *C){
    FILE *arch;
    int num;

    arch=fopen("numeros.txt","r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else{
        iniciaC(C);
        while (fscanf(arch,"%d",&num)== 1){
            poneC(C, num);
        }
        fclose(arch);
    }
}

void MuestraColaSinPerder(TCola *C){
    TElementoC num,centinela;

    centinela = 9999;
    poneC(C,centinela);
    while(consultaC(*C) != centinela){
        sacaC(C,&num);
        printf("%d\n", num);
        poneC(C,num);
    }
    sacaC(C, &centinela);
}
