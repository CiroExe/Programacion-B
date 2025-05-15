#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 5. Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario */

typedef char *TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int profundidadArbol(arbol );
unsigned int cadenaMasLarga(a);
unsigned int cantHijosDerechos(a);

int main(){
    arbol a=NULL;
    int x;
 /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, "Casa");
    addnodo(&a->izq, "Arbol");
    addnodo(&a->izq->izq, "Reloj");
    addnodo(&a->izq->der, "Tramite");

    addnodo(&a->der, "Inteligente");
    addnodo(&a->der->izq, "Jardin");
    addnodo(&a->der->izq->der, "Escuela");

    printf("Profundidad del arbol(Nivel Maximo) -> %d\n", profundidadArbol(a));
    printf("Longitud de la cadena mas larga -> %u\n", cadenaMasLarga(a));
    printf("Cantidad de hijos derechos del arbol binario -> %u\n", cantHijosDerechos(a));

 return 0;
}
int profundidadArbol(arbol a)
{
    int profIzq, profDer;
    if (a == NULL)
        return 0;
    else
    {
        profIzq = profundidadArbol(a->izq);
        profDer = profundidadArbol(a->der);
        return profIzq > profDer ? 1 + profIzq : 1 + profDer;
    }
}
void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

unsigned int cadenaMasLarga(arbol a){
    unsigned int MaxDer, MaxIzq;


    if (a != NULL){
        MaxDer=cadenaMasLarga(a->der);
        MaxIzq=cadenaMasLarga(a->izq);
        if(MaxDer >= strlen(a->dato) && MaxDer >= MaxIzq)
            return MaxDer;
        else
            if (MaxIzq >= strlen(a->dato) && MaxIzq >= MaxDer)
                return MaxIzq;
            else
                return strlen(a->dato);
    }
    else
        return 0;
}

unsigned int cantHijosDerechos(arbol a){

    if (a!=NULL){
        return (a->der != NULL) + cantHijosDerechos(a->der) + cantHijosDerechos(a->izq);
    }
    else
        return 0;
}
