#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodoA{
    TElementoA dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

//Implementar una función iterativa que inserte un elemento en un ABB.


int main()
{
    arbol a = NULL;
    TElementoA num;

    printf("Ingrese numeros(999 para finalizar)\n");
    scanf("%d", &num);
    while(num != 999){
        buscaInsercion(&a, num);
        scanf("%d", &num);
    }
    return 0;
}


void addnodoABB(arbol *a, TElementoA elem){

    if (*a == NULL){
        * a = (arbol)malloc(sizeof(nodoA));
        (*a)->dato= elem;
        (*a)->der = NULL;
        (*a)->izq = NULL;
    }
}

void buscaInsercion(arbol *a, TElementoA elem){
    arbol aux;
    if (*a == NULL)
        addnodoABB(a, elem);
    else{
        aux = *a;
        while (aux != NULL ){
            if (aux->dato < elem)
                aux = aux->der;
            else
                aux = aux->izq;
        }
        addnodoABB(&aux, elem);
    }
}
