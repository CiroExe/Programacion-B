#include <stdio.h>
#include <stdlib.h>

// Dado un �rbol binario que proviene de la transformaci�n de un bosque, determinar qu�
// cantidad de �rboles lo compon�an.

typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void cantArboles(arbol, unsigned int *);

int main(){
 arbol a;
 int x, cont=0;
 /* carga arbol ejemplo. Ej 1 */
 addnodo(&a, 'A');

 addnodo(&a->der, 'B');
 addnodo(&a->der->der, 'L');
 addnodo(&a->der->der->izq, 'M');
 addnodo(&a->der->der->izq->der, 'N');
 addnodo(&a->der->der->izq->der->izq, 'O');
 addnodo(&a->der->izq, 'C');
 addnodo(&a->der->izq->der,'D');
 addnodo(&a->der->izq->der->izq, 'E');
 addnodo(&a->der->izq->der->izq->der, 'F');
 addnodo(&a->der->izq->der->izq->der->der, 'G');
 addnodo(&a->der->izq->der->izq->der->der->der, 'H');
 addnodo(&a->der->izq->der->izq->der->izq, 'I');
 addnodo(&a->der->izq->der->izq->der->izq->der, 'J');
 addnodo(&a->der->izq->der->izq->der->izq->der->der, 'K');

 cantArboles(a, &cont);
 printf("%u", cont);
 return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void cantArboles(arbol a, unsigned int *cont){
    while(a!=NULL){
        printf("%c\n", a->dato);
        (*cont)++;
        a = a->der;
    }
}
