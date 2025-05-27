#include <stdio.h>
#include <stdlib.h>
#define MAX 256

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
void generaVec(arbol, int [], int *);
void muestraVec(int [], int);
int calculaGrado(arbol);
int tieneAlMenosUnoGradoK(arbol, int);
int todosPoseenGradoK(arbol, int);
int main()
{
    arbol bosque=NULL;
    unsigned int K=2;
    int dimension=0, vec[MAX];

    addnodo(&bosque, 7);
    addnodo(&bosque->der, 10);
    addnodo(&bosque->der->der, 52);
    addnodo(&bosque->der->der->izq, 65);
    addnodo(&bosque->der->der->izq->der, 1);
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


    //Inciso B
    generaVec(bosque, vec, &dimension);
    muestraVec(vec,dimension);

    //Inciso C
    todosPoseenGradoK(bosque, 3) ? printf("Todos los arboles que componen al bosque poseen al menos un nodo de grado K") : printf("No cumple");
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

int maxArbol(arbol a){
    int MaxIzq, MaxDer;
    if(a!=NULL){
        MaxIzq=maxArbol(a->izq);
        MaxDer=maxArbol(a->der);
        if(MaxIzq>MaxDer && MaxIzq>=a->dato)
            return MaxIzq;
        else
            if(MaxDer>MaxIzq && MaxDer >= a->dato)
                return MaxDer;
            else
                return a->dato;
    }
    else
        return -99999;
}

void generaVec(arbol bosque, int vec[], int *dimension){
    arbol aux;
    if(bosque!=NULL){
        while(bosque !=NULL){
            aux=bosque->der;
            bosque->der=NULL;
            vec[(*dimension)++]=maxArbol(bosque);
            bosque->der=aux;
            bosque = bosque->der;
        }
    }
}

void muestraVec(int vec[], int dimension){
    int i;
    for(i=0;i<dimension;i++)
        printf("%d\n",vec[i]);
}



/*int calculaGradoArbol(arbol a){
    arbol hijo;
    int maxGrado;
    int cont=0;

    if (a!=NULL){
        hijo=a->izq;
        while(hijo!=NULL){
            cont++;
            maxGrado=calculaGrado(hijo);
            hijo=hijo->der;
        }
        if (cont>maxGrado)
            maxGrado=cont;

        return cont == 0 ? 1:maxGrado;
    }
    else
        return 0;
}*/

int calculaGrado(arbol a){
    arbol hijo;
    int cont=0;
    if (a!=NULL){
        hijo=a->izq;
        while(hijo!=NULL){
            cont++;
            hijo=hijo->der;
        }
        return cont;
    }
}


int tieneAlMenosUnoGradoK(arbol a, int K){

    if (a!=NULL){
        if (calculaGrado(a) == K)
            return 1;
        else
            return tieneAlMenosUnoGradoK(a->izq,K) || tieneAlMenosUnoGradoK(a->der, K); // Sigue recorriendo por izquierda O derecha.
    }
    else
        return 0; //No encuentra ningun nodo de grado K en el arbol.
}

int todosPoseenGradoK(arbol bosque, int K){

    if (bosque!=NULL){
        while(bosque!=NULL && tieneAlMenosUnoGradoK(bosque,K))
            bosque=bosque->der;
        return bosque == NULL;
    }
}
