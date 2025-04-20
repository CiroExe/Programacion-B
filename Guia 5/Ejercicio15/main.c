#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "pila.h"

void CargaCola(TCola *);
void CargaPila(TPila *, TCola *);
void MuestraCola(TCola *C);
void MuestraCompetidores(TPila *, char);

int main()
{
    TCola C;
    TPila P;
    char letra;

    iniciaC(&C);
    iniciaP(&P);

    CargaCola(&C);
    MuestraCola(&C);

    CargaPila(&P, &C);

    printf("Ingrese la letra de los apellidos que desea consultar\t");
    letra = getchar();

    MuestraCompetidores(&P, letra);

    return 0;
}

void CargaCola(TCola *C){
    FILE *arch;
    TElementoC competidor;

    arch=fopen("competidores.txt", "r");

    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else{

        while (fscanf(arch, "%s %s", competidor.apellido, competidor.nombre) == 2) {
            printf("Leido: %s %s\n", competidor.apellido, competidor.nombre); // Línea de debug
            poneC(C, competidor);
        }

        fclose(arch);
    }
}

void MuestraCola(TCola *C) {
    TElementoC competidor;
    TCola aux;

    iniciaC(&aux);  // ¡IMPORTANTE! Iniciar la cola auxiliar

    while (!VaciaC(*C)) {
        sacaC(C, &competidor);
        poneC(&aux, competidor);
        printf("%s\n", competidor.apellido);
    }

    while (!VaciaC(aux)) {
        sacaC(&aux, &competidor);
        poneC(C, competidor);
    }
}


void CargaPila(TPila *P, TCola *C){
    TElementoC competidor;
    TElementoP elemP,act, temp;
    TPila auxP;

    iniciaP(&auxP);

    while(!VaciaC(*C)){
        sacaC(C, &competidor);
        strcpy(elemP,competidor.apellido);
        poneP(&auxP, elemP);
    }

    while(!VaciaP(auxP)){

        sacaP(&auxP, &act);
        while(!VaciaP(*P) && strcmp(P->competidores[P->tope], act)>0){
            sacaP(P, &temp);
            poneP(&auxP, temp);
        }

        poneP(P, act);
    }
}
void MuestraCompetidores(TPila *P, char letra){
    TElementoP apellido;

    letra = toupper(letra);
    while(!VaciaP(*P)){
        sacaP(P, &apellido);

        if (apellido[0] == letra)
            printf("%s\n", apellido);

    }
}


