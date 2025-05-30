#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de
adyacencia.  */

typedef struct nodo{
    char elem;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct {
    char vertice;
    TLista nodosAdy;
}Grafo;

void cargaVertices(Grafo [], unsigned short int * );
void cargaRelaciones(Grafo[], unsigned short int);
void muestraListaAdy(Grafo[], unsigned short int);
unsigned short int gradoEntrada(Grafo [], unsigned short int, char);
char verticeMayorGradoEntrada(Grafo [], unsigned short int);

int main()
{
    Grafo vertices[MAX];
    unsigned short int n=0;
    char v;

    cargaVertices(vertices, &n);
    cargaRelaciones(vertices, n);
    muestraListaAdy(vertices, n);

    printf("Vertice con mayor grado de entrada: %c\n", verticeMayorGradoEntrada(vertices, n));
    return 0;
}

void cargaVertices(Grafo vertices[], unsigned short int *n) {
    char elem;
    do {
        printf("INGRESE ELEMENTO DEL VERTICE:\t");
        scanf(" %c", &elem);  // espacio agregado aquí
        printf("\n");
        if (elem!='0'){
            vertices[*n].vertice = elem;
            vertices[*n].nodosAdy=NULL;
            (*n)++;
        }
    } while (elem != '0');
}
void cargaRelaciones(Grafo vertices[], unsigned short int n){
    unsigned short int k;
    TLista nuevoLista;
    char elemento;

    for(int i=0; i<n;i++){
        printf("Ingrese cantidad de destinos:\t");
        scanf("%hu", &k);
        for(int j=0; j<k;j++){
            printf("Ingrese el elemento a donde se dirige el vertice %c\n", vertices[i].vertice);
            scanf(" %c", &elemento);
            insertaLista(&(vertices[i].nodosAdy), elemento);
        }
    }
}
void insertaLista(TLista *dirNodo, char elem){
    TLista aux, nuevo;

    nuevo=(nodo *)malloc(sizeof(nodo));
    nuevo->elem=elem;
    nuevo->sig=NULL;
    if(*dirNodo==NULL)
        *dirNodo = nuevo;
    else{
        aux=*dirNodo;
        while(aux->sig !=NULL)
            aux=aux->sig;
        aux->sig=nuevo;
    }
}

void muestraListaAdy(Grafo vertices[], unsigned short int n){
    TLista aux;
    for (int i=0;i<n;i++){
        printf("%c =>\t", vertices[i].vertice);
        aux=vertices[i].nodosAdy;
        while(aux!=NULL){
            (aux->sig == NULL)? printf("%c ", aux->elem):printf("%c ->", aux->elem);
            aux=aux->sig;
        }
        printf("\n");
    }
}

unsigned short int gradoEntrada(Grafo vertices[], unsigned short int n, char v){
    TLista aux;
    unsigned short int cont=0;

    for(int i=0; i<n; i++){
        if(vertices[i].vertice != v){
            aux=vertices[i].nodosAdy;
            while(aux!=NULL){
                if (aux->elem == v)
                    cont++;
                aux=aux->sig;
            }
        }
    }
    return cont;
}

char verticeMayorGradoEntrada(Grafo vertices[], unsigned short int n){
    unsigned short int gradoEntradaAct, max=gradoEntrada(vertices, n, vertices[0].vertice);
    char maxV=vertices[0].vertice;

    for(int i=1;i<n;i++){
        gradoEntradaAct=gradoEntrada(vertices, n, vertices[i].vertice);
        if (gradoEntradaAct > max){
            max=gradoEntradaAct;
            maxV=vertices[i].vertice;
        }
    }
    return maxV;
}


