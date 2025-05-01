#include <stdio.h>
#include <stdlib.h>
#define MAX 256

//Declaracion de tipos para la lista doble con sublistas.
typedef struct nodito{
    int elem;
    struct nodito *sig;
}nodito;
typedef nodito* Sublista;

typedef struct nodoD{
    int A, B;
    Sublista sub;
    struct nodoD *ant, *sig;
}nodoD;
typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri, ult;
}

//Declaracion de tipos para la lista paralela a la lista doblemente enlazada.

typedef struct nodoL{
    float promedio;
    unsigned int noPertenecen;
    struct nodoL *sig;
}nodoL;
typedef nodoL *TLista;


//Asumo que la lista ya fue cargada.
void GeneroLista(TLista *L, TListaD LD){
    PnodoD ant = NULL, aux = LD;
    Sublista actS;
    unsigned int contEnteros;
    int acumEnteros;

    *L = NULL;

    while (aux != NULL){
        nuevoLista=(TListaL)malloc(sizeof(nodoL));
        nuevoLista->noPertenecen = 0;
        actS = aux->sub;
        contEnteros = 0;
        acumEnteros = 0;
        while(actS != NULL){
            contEnteros++;
            acumEnteros += actS->elem;
            if (actS->elem < A || actS->elem > B)
                nuevoLista->noPertenecen++;
            actS = actS->sig;
        }
        nuevoLista->promedio = (contEnteros != 0) ? float(acumEnteros)/contEnteros: 0;
        if (*L == NULL){
            nuevoLista->sig = *L;
            *L = nuevoLista;
        }
        else{
            ant=NULL;
            act = *L;
            while (act != NULL ){
                ant = act;
                act = act->sig;
            }
            ant->sig = nuevoLista;
            nuevoLista->sig = act;
        }
        ant = aux;
        aux = aux->sig;
    }
}


