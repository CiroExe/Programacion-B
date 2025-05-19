#include <stdio.h>
#include <stdlib.h>
#define MAX 256

typedef struct nodoA{
    char caracter;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void addnodoABB(arbol *, char);
void cargaABB(arbol *);
void generaVec(arbol, char[], unsigned int *);
void muestraVec(char [], unsigned int);
int main()
{
    arbol a = NULL;
    unsigned int n=0;
    char vec[MAX];

    cargaABB(&a);
    generaVec(a, vec, &n);
    muestraVec(vec, n);
    return 0;
}

void addnodoABB(arbol *a, char caracter){

    if (*a == NULL){
        *a = (arbol)malloc(sizeof(nodoA));
        (*a)->caracter=caracter;
        (*a)->izq = NULL;
        (*a)->der = NULL;
    }
    else
        if (caracter > (*a)->caracter)
            addnodoABB(&(*a)->der, caracter);
        else
            addnodoABB(&(*a)->izq, caracter);
}

void cargaABB(arbol *a){
    char car;
    printf("Ingrese un caracter(0 para terminar)\n");
    do{
        scanf("%c", &car);
        if (car != 0)
            addnodoABB(a, car);
    }while(car != '0');
}

void generaVec(arbol a, char vec[], unsigned int *n){

    if (a != NULL){
        generaVec(a->der, vec, n);
        vec[*n]=a->caracter;
        (*n)++;
        generaVec(a->izq, vec, n);
    }
}

void muestraVec(char vec[], unsigned int n){
    for (int i=0; i<n; i++)
        printf("%c\t", vec[i]);
}




