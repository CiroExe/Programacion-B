#include <stdio.h>
#include <stdlib.h>
typedef int TElementoA;
typedef struct nodo{
        TElementoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElementoA e);
int sumaMultiplos(arbol);
int cantHojas(arbol);
int busca(arbol, TElementoA);
int main(){
    arbol a;
    int x;
    /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);

    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);

    printf("%d\n",sumaMultiplos(a));
    printf("%d\n", cantHojas(a));
    printf("%d\n", busca(a, 6));

 return 0;

}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int sumaMultiplos(arbol a){
    if (a != NULL){
        if (a->dato % 3 == 0)
            return a->dato + sumaMultiplos(a->der)+ sumaMultiplos(a->izq);
        else
            return sumaMultiplos(a->der)+ sumaMultiplos(a->izq);
    }
    else
        return 0;
}

int cantHojas(arbol a){
    if (a != NULL){
        if (a->der == NULL && a->izq == NULL)
            return 1;
        else
            return cantHojas(a->izq)+cantHojas(a->der);
    }
    else{
        return 0;
    }
}

int busca(arbol a, TElementoA dato){
    if (a!= NULL){
        if (a->dato == dato)
            return 1;
        else
            return busca(a->izq, dato) + busca(a->der, dato);
    }
    return 0;
}
