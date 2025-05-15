#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
//void sumaGradoUno(arbol, unsigned int, int, int *);
int suma(arbol, unsigned, unsigned);

int main(){
    arbol a=NULL;
    int X;
    int suma= 0;
    /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->izq->izq, 1);
    addnodo(&a->izq->der, 6);
    addnodo(&a->izq->der->izq, 1);

    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);

    scanf("%d", &X);
    sumaGradoUno(a, 1, X, &suma);

   printf("%d", suma);
 return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void sumaGradoUno(arbol a, unsigned int nivel, int X, int *suma){

    if (a != NULL){

        if (nivel == X)
            if ((a->izq == NULL && a->der != NULL) || (a->izq != NULL && a->der == NULL))
                (*suma)+=a->dato;

        sumaGradoUno(a->izq, nivel+1, X, suma);
        sumaGradoUno(a->der, nivel+1, X, suma);
    }
}

