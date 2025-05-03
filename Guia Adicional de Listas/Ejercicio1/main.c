#include <stdio.h>
#include <stdlib.h>

typedef struct nodoL{
    int elem;
    struct nodoL *sig;
}nodoL;
typedef nodoL *TLista;

//Asumo listas ya cargadas-


//Inciso A
int sonIguales(TLista L1, TLista L2){
    TLista aux1 = L1, aux2 = L2;

    while (aux1 != NULL && aux2 != NULL && aux1->elem == aux2->elem){
        aux1 = aux1->sig;
        aux2 = aux2->sig;
    }

    return aux1 == NULL && aux2 == NULL;
}

//Inciso B
void UneListas(TLista *L1, TLista *L2){
    TLista aux = *L1, aux2;

    while(aux->sig != NULL)
        aux = aux->sig;

    if (L2->elem > aux->elem)
        aux->sig = *L2;
    else{
        aux2 = *L2;
        while (aux2->sig != NULL)
            aux2 = aux2->sig;
        aux2->sig = *L1;
        *L1 = *L2;
    }
}

//Inciso C
void eliminaNodos(TLista *L1, TLista L2){
    unsigned int cont = 0;
    TLista elim,ant= NULL, aux = *L1;


    while (aux != NULL && L2 != NULL){
        if (L2->elem == cont){
            elim = aux;
            if (aux == *L1){
                *L1 = (*L1)->sig;
                aux = *L1;
            }
            else{
                ant->sig = aux->sig;
                aux = aux->sig;
            }
            free(elim);
            L2 = L2->sig;
        }
        else {
            ant = aux;
            aux = aux->sig;
        }
        cont++;
    }
}


