#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A */

typedef char *TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void nivelMaxLong(arbol, unsigned int *, unsigned int, unsigned int *);

int main(){
    arbol a=NULL;
    unsigned int MaxLong=0, nivelMax=0;
    int x;
 /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, "Casa");
    addnodo(&a->izq, "Arbol");
    addnodo(&a->izq->izq, "Reloj");
    addnodo(&a->izq->der, "Tramite");

    addnodo(&a->der, "Inteligente");
    addnodo(&a->der->izq, "Jardin");
    addnodo(&a->der->izq->der, "Arbitrario");

    nivelMaxLong(a, &MaxLong, 1, &nivelMax);
    printf("Nivel donde se encuentra la cadena de mayor longitud que empieza con A %u\n", nivelMax);
    printf("Cadena con mayor longitud empezada con A %u\n", MaxLong);
 return 0;
}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void nivelMaxLong(arbol a, unsigned int *MaxLong,unsigned int nivel, unsigned int *nivelMax){
    if (a != NULL){
        if (a->dato[0] == 'A')
            if (strlen(a->dato) > (*MaxLong)){
                (*MaxLong)=strlen(a->dato);
                (*nivelMax) = nivel;
            }

        nivelMaxLong(a->der, MaxLong, nivel+1, nivelMax);
        nivelMaxLong(a->izq, MaxLong, nivel+1,nivelMax);
    }
}
