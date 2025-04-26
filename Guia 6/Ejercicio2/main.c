#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;
}nodo;
typedef nodo *TLista;

void MuestraLista(TLista);
void CargaListaInverso(TLista *, int [], unsigned int);
void CargaLista(TLista *, int [], unsigned int);
void CargaListaOrdenada(TLista *, int[], unsigned int);

int main()
{
    TLista L1, L2, L3;
    int V[]= {3, 5, 10, -3, 4};

    //Inciso a
    CargaListaInverso(&L1,V,5);
    MuestraLista(L1);
    //Inciso b
    CargaLista(&L2,V,5);
    MuestraLista(L2);
    //Inciso c
    CargaListaOrdenada(&L3,V,5);
    MuestraLista(L3);


    return 0;
}


void CargaListaInverso(TLista *L, int V[], unsigned int n){
    TLista ant, nuevo;
    unsigned int i;

    *L=NULL;

    for (i=0; i<n; i++){
        nuevo=(TLista)malloc(sizeof(nodo));
        nuevo->dato=V[i];
        nuevo->sig=*L;
        *L = nuevo;
    }
}

void CargaLista(TLista *L, int V[], unsigned int n){
    TLista nuevo, act;
    int i;

    *L=NULL;

    for (i=0;i<n;i++){
        nuevo=(TLista)malloc(sizeof(nodo));
        nuevo -> dato=V[i];
        nuevo -> sig=NULL;
        if(*L == NULL)
            *L=nuevo;
        else{
            act=*L;
            while(act-> sig != NULL)
                act = act -> sig;

            act -> sig= nuevo;
        }

    }
}

void CargaListaOrdenada(TLista *L, int V[], unsigned int n){
    TLista nuevo,ant,act;
    int i;

    *L=NULL;

    for(i=0; i<n; i++){
        nuevo=(TLista)malloc(sizeof(nodo));
        nuevo -> dato=V[i];

        ant = NULL;
        act=*L;

        while(act != NULL && act->dato < V[i]){
            ant=act;
            act = act->sig;
        }

        if (ant == NULL){
            nuevo->sig=*L;
            *L=nuevo;
        }
        else{
            ant -> sig=nuevo;
            nuevo -> sig = act;
        }
    }
}


void MuestraLista(TLista L){
    TLista aux;

    aux = L;
    while(aux != NULL){
        printf("%d\t", aux -> dato);
        aux = aux->sig;
    }
    printf("\n");
}

