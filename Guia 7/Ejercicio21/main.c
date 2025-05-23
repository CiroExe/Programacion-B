#include <stdio.h>
#include <stdlib.h>

/*  Dado un árbol binario que proviene de la transformación de un bosque,
    a) hallar la cantidad de árboles del bosque que tenían altura al menos K (dato de entrada)
    b) generar un arreglo con la clave mayor de cada uno de los árboles que conforman el bosque.
    c) verificar que todos los árboles contengan al menos un nodo de grado K (dato de entrada).
*/

typedef int TElementoA;
typedef struct nodoA{
    TElementoA dato;
    struct nodoA *izq, *der;
}nodoA;
typedef nodoA *arbol;

void addnodo(arbol *, TElementoA);
int alturaArbol(arbol);
int cantAlturaK(arbol, unsigned int);
int main()
{
    arbol bosque=NULL;
    unsigned int K=2;

    addnodo(&bosque, 7);
    addnodo(&bosque->der, 10);
    addnodo(&bosque->der->der, 52);
    addnodo(&bosque->der->izq, 23);
    addnodo(&bosque->der->izq->der, 54);
    addnodo(&bosque->der->izq->der->izq, 18);
    addnodo(&bosque->der->izq->der->izq->der, 76);
    addnodo(&bosque->der->izq->der->izq->der->der, 31);
    addnodo(&bosque->der->izq->der->izq->der->der->der, 43);
    addnodo(&bosque->der->izq->der->izq->der->der->der->der, 40);
    addnodo(&bosque->der->izq->der->izq->der->der->der->der->izq, 90);
    addnodo(&bosque->der->izq->der->izq->der->izq, 87);
    addnodo(&bosque->der->izq->der->izq->der->izq->der, 66);
    addnodo(&bosque->der->izq->der->izq->der->izq->der->der, 4);

    //Inciso A
    if (cantAlturaK(bosque, K) == 0)
        printf("Ningun arbol tiene una altura de a lo sumo %u\n", K);
    else
        printf("Cantidad de arboles que pertenecen al bosque con altura de a lo sumo %u -> %d\n",K, cantAlturaK(bosque,K));




    return 0;
}

void addnodo(arbol* a, TElementoA e) {
    *a = (arbol)malloc(sizeof(nodoA));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int alturaArbol(arbol a){
    int Izq, Der;
    if (a!=NULL){
        Izq=1+alturaArbol(a->izq);
        Der=alturaArbol(a->der);
        return Izq > Der ? Izq : Der;
    }
    else
        return 0;
}

int cantAlturaK(arbol bosque, unsigned int K){
    int cont=0;
    if (bosque!=NULL){
        while (bosque!=NULL){
            if (alturaArbol(bosque) >= K)
                cont++;
            bosque = bosque->der;
        }
        return cont;
    }
    return 0;

}
