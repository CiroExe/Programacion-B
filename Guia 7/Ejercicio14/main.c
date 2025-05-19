#include <stdio.h>
#include <stdlib.h>
#define MAX 256

typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void addnodoABB(arbol *, int);
void cargaABB(arbol *);
int esABB(arbol, int, int);

int main()
{
    arbol a = NULL;

    cargaABB(&a);
    //esABB(a, -99999, 99999) ? printf("Es ABB") : printf("No es ABB");
    if (esABB(a,-9999, 9999)){
        printf("Es un ABB.\n");
    }
    else{
        printf("No es un ABB.\n");
    }


    return 0;
}

void addnodoABB(arbol *a, int num){

    if (*a == NULL){
        *a = (arbol)malloc(sizeof(nodoA));
        (*a)->dato=num;
        (*a)->izq = NULL;
        (*a)->der = NULL;
    }
    else
        if (num > (*a)->dato)
            addnodoABB(&(*a)->der, num);
        else
            addnodoABB(&(*a)->izq, num);
}

void cargaABB(arbol *a){
    int num;
    printf("Ingrese un numero(9999 para terminar)\n");
    do{
        scanf("%d", &num);
        if (num != 9999)
            addnodoABB(a, num);
    }while(num != 9999);
}

int esABB(arbol a, int maximo, int minimo){
    if (a!=NULL){
        if (a->dato >= minimo && a->dato <maximo)
            return esABB(a->izq, minimo, a->dato) && esABB(a->der, a->dato, maximo);
        else
            return 0;
    }
    else
        return 1;
}
