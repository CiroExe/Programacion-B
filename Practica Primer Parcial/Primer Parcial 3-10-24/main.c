#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

typedef struct {
    unsigned int hora, minuto;
}THora;

typedef struct nodito{
    char patente[8], hora[6];
    unsigned int fechaJuliana;
    THora tiempo_abonado, tiempo_ocupacion;
    struct nodito *sig;
}nodito;
typedef nodito *Sublista;

typedef struct nodoD{
    char codAgente[6], nomAp[31], estudiante;
    Sublista sub;
    struct nodoD *ant, *sig;
}nodoD;
typedef nodoD *PnodoD;

typedef struct {
    PnodoD pri, ult;
}TListaD;



THora convierte(unsigned int minutos){
    THora reg;

    reg.hora = minutos / 60;
    reg.minuto = minutos % 60;

    return reg;
}

void actualizaLista(TCola *C, TListaD LD){
    PnodoD aux;
    TElementoC centinela, reg;
    Sublista antS, actS, nuevoSub;

    strcpy(centinela.codAgente, 'ZZZZZ');
    poneC(C, centinela);

    sacaC(C, &reg);
    while(strcmp(reg.codAgente, centinela.codAgente)){

        aux = LD.pri;
        while(aux != NULL && strcmp(reg.codAgente, aux->codAgente) < 0)
            aux = aux->sig;

        if (strcmp(reg.codAgente, aux->codAgente) == 0){
            if (reg.tiempo_pagado < reg.tiempo_ocupacion && (reg.fechaJuliana>243 && reg.fechaJuliana<=274)){
                nuevoSub = (Sublista)malloc(sizeof(nodito));
                strcpy(nuevoSub->patente, reg.patente);
                strcpy(nuevoSub->hora, reg.HoraMulta);
                nuevoSub->fechaJuliana = reg.fechaJuliana;
                nuevoSub->tiempo_abonado = convierte(reg.tiempo_pagado);
                nuevoSub->tiempo_ocupacion = convierte(reg.tiempo_ocupacion);

                if (aux->sub == NULL || strcmp(reg.patente, actS->patente) < 0){
                    nuevoSub->sig = actS;
                    aux->sub = nuevoSub;
                }
                else{
                    antS = aux->sub;
                    actS = aux->sub->sig;

                    while(actS->sig != NULL && strcmp(nuevoSub->patente, actS->patente) > 0){
                        antS = actS;
                        actS = actS->sig;
                    }

                    nuevoSub->sig = actS;
                    antS->sig = nuevoSub;
                }
            }
            else
                poneC(C, reg);
        }
        sacaC(C, &reg);
    }

}

int esMesPar(unsigned int fechaJuliana){
    int cumple = 0;

    switch(fechaJuliana){
        case fechaJuliana>31 && fechaJuliana<
    }
}

void generaArchivo(TListaD LD, char AG[], unsigned int K){
    FILE *arch;
    PnodoD aux;


    arch=fopen("MULTAS.DAT","wb");
    if (arch == NULL)
        printf("No se pudo abrir el archivo");
    else{
        aux = LD.pri;
        while(strcmp(AG, aux->codAgente) < 0)
            aux = aux->sig;

        actS = aux->sub;
        while (actS != NULL){
            cont++;
            if (esMesPar(actS->fechaJuliana) && (strcmp(actS->hora, "12:00") < 0 || strcmp(actS->hora, "18:00") > 0)){
                strcmp(reg.patente, actS->patente);
                reg.fechaJuliana = actS->fechaJuliana;
                reg.tiempoAbonado = tiempo_abonado;
                reg.tiempoOcupacion = tiempo_ocupacion;
                fwrite(&reg, sizeof(reg), 1 , arch);
            }
            actS = actS->sig;
        }

        if (cont > K && aux->estudiante == 'S')
            printf("Al agente %s le corresponde la bonificacion del 15%\n");
        else
            printf("Al agente %s no le corresponde la bonificacion del 15%\n");
    }
}
void EliminaLD(TListaD *LD, char X[]){
    PnodoD aux;
    Sublista antS, actS, elim;

    if ((*LD).pri != NULL){


        aux = (*LD).pri;
        while (aux != NULL && strcmp(X, aux->codAgente) < 0)
            aux = aux->sig;

        if (aux != NULL && strcmp(X, aux->codAgente) == 0){

            if (aux->sub != NULL && aux->sub->patente[0] == 'A' && aux->sub->patente[1]=='F'){
                elim = aux->sub;
                aux->sub = aux->sub->sig;
                free(elim);
            }
            else{
                antS = aux->sub;
                actS = aux->sub->sig;
                while (actS != NULL){
                    if (actS->patente[0]=='A' && actS->patente[1]=='F'){
                        elim = actS;
                        antS->sig = actS->sig;
                        actS = elim->sig;
                        free(elim);
                    }
                    else{
                        antS = actS;
                        actS = actS->sig;
                    }
                }
            }

            if (aux->sub == NULL){
                if (aux == (*LD).pri){
                    (*LD).pri = aux->sig;
                    (*LD).pri->ant = NULL;
                }
                else{
                    if (aux == (*LD).ult){
                        (*LD).ult = aux->ant;
                        (*LD).ult->sig = NULL;
                    }
                    else{
                        aux->ant->sig = aux->sig;
                        aux->sig->ant = aux->ant;
                    }
                }
                free(aux);
            }
        }
    }
}

int main()
{
    TListaD LD;
    TCola C;
    char AG[11],X[11];
    unsigned int K;

    CargaLD(&LD);
    iniciaC(&C);
    CargaC(&C);

    actualizaLista(&C, LD);

    printf("Ingrese agente\n");
    scanf("%s", AG);
    printf("Ingrese cantidad de multas a supear\n");
    scanf("%u", K);
    generaArchivo(LD, AG, K);

    printf("Ingrese agente\n");
    scanf("%s", X);
    EliminaLD(&LD, X);
    return 0;
}

----------------------------------------------------------------

typedef struct {
    char codAgente[11], HoraMulta[6];
    unsigned int fechaJuliana, tiempo_pagado, tiempo_ocupacion;
}TElementoC;

typedef struct nodoC {
    TElementoC elem;
    struct nodoC *sig;
}nodoC;

typedef struct {
    nodoC *pri, ult;
}TCola;

void SacaC(TCola *C, TElementoC *elem){
    nodoC *elim;
    if ((*C).pri != NULL){
        elim = (*C).pri;
        *elem = (*C).pri->elem;
        (*C).pri = (*C).pri->sig;
        if ((*C).pri == NULL)
            (*C).ult = NULL;
        free(aux);
    }
}
