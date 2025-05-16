#include <stdio.h>
#include <stdlib.h>
typedef int TElementoA;
typedef struct nodoA{
    TElementoA dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void cargaABB(arbol *);
void addnodoABB(arbol *a, TElementoA);
int minABB(arbol);
int main()
{
    arbol a = NULL;

    cargaABB(&a);
    printf("Minimo del arbol binario de busqueda -> %d\n", minABB(a));
    return 0;
}


void cargaABB(arbol *a){
    int num;

    printf("Ingrese numero(9999 para finalizar)\t");
    scanf("%d", &num);
    printf("\n");
    while(num != 9999) {
        addnodoABB(a, num);
        printf("Ingrese numero(9999 para finalizar)\t");
        scanf("%d", &num);
    }
}

void addnodoABB(arbol *a, TElementoA elem){

    if (*a == NULL){
        *a =(arbol)malloc(sizeof(nodoA));
        (*a)->dato = elem;
        (*a)->der = NULL;
        (*a)->izq = NULL;
    }
    else
        if ((*a)->dato < elem)
            addnodoABB(&((*a)->der), elem);
        else
            addnodoABB(&((*a)->izq),elem);
}

int minABB(arbol a){
    if (a != NULL)
        return a->izq != NULL ? minABB(a->izq) : a->dato;
    else
        return 0;
}
