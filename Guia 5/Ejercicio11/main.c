#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void CargaCola(TCola *);
void MuestraEmpleado(TCola *, float *, char []);
convierteSegundos(int);


int main()
{
    TCola C;
    float tiempo_espera;
    char legajoMax[9];

    iniciaC(&C);
    CargaCola(&C);
    MuestraEmpleado(&C, &tiempo_espera, legajoMax);

    printf("El tiempo promedio de espera fue de: %.2f segundos\n", tiempo_espera);
    printf("El legajo con mayor tiempo de espera fue: %s", legajoMax);

    return 0;
}

void CargaCola(TCola *C){
    FILE *arch;
    TElementoC empleado;

    arch = fopen("empleados_microondas.txt","r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo\n");
    else{

        while(fscanf(arch,"%s %d %d",empleado.legajo, &empleado.arribo, &empleado.usoHorno) == 3){
            poneC(C, empleado);
        }
        fclose(arch);
    }
}


int convierteSegundos(int segundos){
    if (segundos >= 60)
        return segundos / 60;
    else
        return 0;
}

void MuestraEmpleado(TCola *C, float *tiempo_espera, char legajoMax[]) {
    TElementoC empleado;
    int acum_uso=0, cont=0,max, minAct;

    minAct=0;
    max=-1;
    while (!VaciaC(*C)) {
        sacaC(C, &empleado);
        cont++;
        acum_uso+=empleado.usoHorno;

        if (empleado.usoHorno > max){
            max=empleado.usoHorno;
            strcpy(legajoMax, empleado.legajo);
        }

        minAct+=convierteSegundos(empleado.arribo);
        printf("Empleado %d\n", cont);
        printf("Legajo: %s\n", empleado.legajo);
        printf("Empezo: 12:%.2d\n", minAct);
        minAct+=convierteSegundos(empleado.usoHorno);
        printf("Termino: 12:%02d\n", minAct);
        printf("\n");
    }

    *tiempo_espera = (cont > 0) ? (float)acum_uso / cont : 0;
}
