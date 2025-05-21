#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;
typedef struct nodoA{
    TElementoA dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

//Implementar una función iterativa que inserte un elemento en un ABB.

void addnodoABB(arbol *, TElementoA);
void buscaInsercion(arbol *, TElementoA);
void muestraArbolInorden(arbol);
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
    muestraArbolInorden(a);
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

/*void buscaInsercion(arbol *a, TElementoA elem){
    arbol aux, ant;
    if (*a == NULL)
        addnodoABB(a, elem);
    else{
        aux = *a;
        ant = NULL;
        while (aux != NULL){
            ant=aux;
            if (aux->dato < elem)
                aux = aux->der;
            else
                aux = aux->izq;
        }

        if(ant->dato > elem)
            addnodoABB(&(ant->izq), elem);
        else
            addnodoABB(&(ant->der), elem);

    }
}*/

void buscaInsercion(arbol *a, TElementoA elem) {
    while (*a != NULL) {
        if ((*a)->dato < elem)
            a = &((*a)->der);
        else
            a = &((*a)->izq);
    }
    addnodoABB(a, elem);
}


void muestraArbolInorden(arbol a){
    if(a!=NULL){
        muestraArbolInorden(a->izq);
        printf("%d\t", a->dato);
        muestraArbolInorden(a->der);
    }

}
