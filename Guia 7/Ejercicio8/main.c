#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

typedef char TElementoA[MAX];
typedef struct nodoA{
    TElementoA competidor;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void addnodo(arbol *, TElementoA);
void muestraCompetidor(arbol, int, int);
void competidores(arbol, int *);
int main()
{
    arbol a = NULL;
    int cant=0;
    addnodo(&a, "Djokovic");

    addnodo(&a->izq, "Nadal");
    addnodo(&a->izq->izq, "Djokovic");
    addnodo(&a->izq->der, "Federer");

    addnodo(&a->der, "Djokovic");
    addnodo(&a->der->izq, "Schwartzmann");
    addnodo(&a->der->der, "Nadal");

    //Nombre del ganador
    printf("Ganador\n");
    muestraCompetidor(a, 1, 1);

    //Nombre de los finalistas
    printf("Finalistas\n");
    muestraCompetidor(a, 2,1);

    //Nombre de los semifinalistas
    printf("Semifinalistas\n");
    muestraCompetidor(a, 3, 1);

    printf("\n");
    //Muestra todos los competidores
    competidores(a, &cant);
    printf("Cantidad de competidores %d\n",cant);

    return 0;
}

void addnodo(arbol *a, TElementoA competidor){

    *a = (arbol)malloc(sizeof(nodoA));
    (*a)->der = NULL;
    (*a)->izq = NULL;
    strcpy((*a)->competidor, competidor);
}

void muestraCompetidor(arbol a, int nivel, int nivelAct){
    if (a!=NULL){
        if (nivel == nivelAct)
            printf("%s\n", a->competidor);
        else{
            muestraCompetidor(a->der, nivel, nivelAct+1);
            muestraCompetidor(a->izq, nivel, nivelAct+1);
        }

    }
}

void competidores(arbol a, int *cant){
    int esta;
    if (a!=NULL){
        if (a->der == NULL && a->izq == NULL){
            (*cant)++;
            printf("%s\n",a->competidor);    
        }
        else{
             competidores(a->der, cant);
             competidores(a->izq, cant);
        }
    }
}