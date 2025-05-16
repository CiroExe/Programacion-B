#include <stdio.h>
#include <stdlib.h>

/*. Determinar cuántos elementos de un ABB son mayores que A y menores que B. A y B son
    parámetros de entrada */

typedef int TElementoA;
typedef struct nodoA{
    TElementoA dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void cargaArbol(arbol *);
void addnodo(arbol *, TElementoA );
int Cuenta(arbol, int, int);

int main()
{
    int A, B;
    arbol a =  NULL;

    cargaArbol(&a);

    printf("Ingrese A y B\n");
    scanf("%d %d", &A, &B);

    printf("%d elementos son mayores que %d y menores que %d \n",Cuenta(a, A, B), A, B);

    return 0;
}

void cargaArbol(arbol *a){
    int num;

    printf("Ingrese numero (9999 para finalizar)\t");
    scanf("%d",&num);
    printf("\n");
    while(num != 9999){
        addnodo(a, num);
        printf("Ingrese numero (9999 para finalizar)\t");
        scanf("%d",&num);
        printf("\n");
    }
}


void addnodo(arbol *a, TElementoA elem){

    if(*a == NULL){
        *a = (arbol)malloc(sizeof(nodoA));
        (*a)->dato = elem;
        (*a)->der = NULL;
        (*a)->izq = NULL;
    }
    else
        if ((*a)->dato > elem)
            addnodo(&((*a)->izq), elem);
        else
            addnodo(&((*a)->der), elem);
}

//Recorre ABB
int Cuenta(arbol a, int A, int B){
    if (a != NULL){
        if (a->dato <= A)
            return Cuenta(a->der, A , B);
        else
            if (a->dato >= B)
                return Cuenta(a->izq, A, B);
            else
                return 1 + Cuenta(a->der, A, B) + Cuenta(a->izq, A, B);
    }
    else
        return 0;
}
// Recorre sin ABB (Recorre todo el arbol)
int Cuenta(arbol a, int A, int B){
    if (a != NULL){
        if (a->dato >A && a->dato < B)
            return 1 + Cuenta(a->der, A, B) + Cuenta(a->izq, A, B);
        else
            return Cuenta(a->der, A, B) + Cuenta(a->izq, A, B);
    }
    else
        return 0;
}

