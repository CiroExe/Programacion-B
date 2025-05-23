#include <stdio.h>
#include <stdlib.h>


/* . Dado un árbol binario proveniente de la conversión de un árbol general:
a) hallar la cantidad de nodos que habia en niveles impares.
b) obtener el promedio de las claves cuyo grado era K (dato de entrada).
c) obtener la altura del árbol original
d) determinar el grado del árbol original.  */

typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
int cantNodos(arbol, int);
int altura_original(arbol);
void grado_original(arbol, int,int*);
void promedio(arbol, int, int*, int*);

int main(){
    arbol a;
    int gradoMax = 0, K = 1, acum = 0, cont = 0;

 /* carga arbol ejemplo. Ej 1 */
    addnodo(&a, 10);
    addnodo(&a->izq, 23);
    addnodo(&a->izq->der, 54);
    addnodo(&a->izq->der->izq, 18);
    addnodo(&a->izq->der->izq->der, 76);
    addnodo(&a->izq->der->izq->der->izq, 87);
    addnodo(&a->izq->der->izq->der->der, 31);
    addnodo(&a->izq->der->izq->der->der->der, 43);
    addnodo(&a->izq->der->izq->der->der->der->der, 40);
    addnodo(&a->izq->der->izq->der->der->der->der->izq, 90);
    addnodo(&a->izq->der->izq->der->izq->der, 66);
    addnodo(&a->izq->der->izq->der->izq->der->der, 4);
    addnodo(&a->izq->der->izq->der->izq->der->der->izq, 9);
    //Inciso A
    printf("Cantidad de nodos en niveles impares -> %d\n", cantNodos(a, 0));

    //Inciso B
    promedio(a, K, &acum, &cont);
    printf("Promedio -> %.2f\n", (float)acum/cont);


    //Inciso C
    printf("Altura original -> %d\n", altura_original(a));

    //Inciso D
    grado_original(a, 0,&gradoMax);
    printf("Grado original -> %d\n", gradoMax);

 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int cantNodos(arbol a, int nivel){
    if(a==NULL)
        return 0;
    else{
        return (nivel % 2 != 0) + cantNodos(a->izq, nivel+1) + cantNodos(a->der, nivel);
    }
}

int altura_original(arbol a){
    int altIzq, altDer;
    if (a!=NULL){
        altIzq = 1 + altura_original(a->izq);
        altDer = altura_original(a->der);
        return altIzq > altDer ? altIzq : altDer;
    }
    else
        return 0;
}

void grado_original(arbol a, int gradoAct,int *gradoMax) {

    if (a!=NULL){

        if (a->der!=NULL)
            grado_original(a->der, gradoAct+1, gradoMax);
        else
            if (gradoAct > *gradoMax)
                *gradoMax = gradoAct;

        grado_original(a->izq, 1, gradoMax);

    }
}

void promedio(arbol a, int K, int *acum, int *cont){
    unsigned int cantHijos=0;
    arbol hijo;
    if (a!=NULL){
        hijo=a->izq;
        while(hijo!=NULL){
            cantHijos++;
            hijo = hijo->der;
        }

        if (cantHijos == K){
            *acum+=a->dato;
            (*cont)++;
        }


        promedio(a->izq, K, acum, cont);
        promedio(a->der, K, acum, cont);
    }
}

int gradoNodo(arbol a){   //Devuelve grado de la raiz
    unsigned int Grado;
    if (a!=NULL){
        Grado=1;
        a=a->izq;
        while(a!=NULL){
            Grado++;
            a=a->der;
        }
        return Grado;
    }
    else
        return 0;
}

