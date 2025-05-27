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
}nodoGrafo;

void cargaVertices(nodoGrafo [], unsigned short int * );
void cargaRelaciones(nodoGrafo[], unsigned short int);
void muestraListaAdy(nodoGrafo[], unsigned short int);
unsigned short int gradoEntrada(nodoGrafo [], unsigned short int, char);
unsigned short int gradoSalida(nodoGrafo [], unsigned short int, char);
unsigned short int gradoVertice(nodoGrafo [], unsigned short int, char);

int main()
{
    nodoGrafo vertices[MAX];
    unsigned short int n=0;
    char v;

    cargaVertices(vertices, &n);
    cargaRelaciones(vertices, n);
    muestraListaAdy(vertices, n);

    printf("Ingrese un vertice para calcular su grado\n");
    scanf(" %c", &v);


    //Inciso A
    printf("Grado de entrada del vertice %c : %hu\n", v, gradoEntrada(vertices, n, v));

    //Inciso B
    printf("Grado de salida del vertice %c : %hu\n", v, gradoSalida(vertices, n, v));

    //Inciso C
    printf("Grado del vertice %c : %hu\n", v, gradoVertice(vertices, n, v));
    return 0;
}

void cargaVertices(nodoGrafo vertices[], unsigned short int *n) {
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
void cargaRelaciones(nodoGrafo vertices[], unsigned short int n){
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

void muestraListaAdy(nodoGrafo vertices[], unsigned short int n){
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

unsigned short int gradoEntrada(nodoGrafo vertices[], unsigned short int n, char v){
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

unsigned short int gradoSalida(nodoGrafo vertices[], unsigned short int n, char v){
    TLista aux;
    unsigned short int cont=0, i = 0, encontroVertice=0;

    while (i<n && !encontroVertice){
        if(vertices[i].vertice == v){
            encontroVertice=1;
            aux=vertices[i].nodosAdy;
            while(aux!=NULL){
                cont++;
                aux=aux->sig;
            }
        }
        i++;
    }
    return cont;
}

unsigned short int gradoVertice(nodoGrafo vertices[], unsigned short int n, char v){
    int ciclo=0, i=0;
    TLista aux;
    while(i<n && !ciclo){
        if (vertices[i].vertice == v){
            aux=vertices[i].nodosAdy;
            while(aux!=NULL){
                ciclo = aux->elem == vertices[i].vertice;
                aux=aux->sig;
            }
        }
        i++;
    }
    return gradoEntrada(vertices, n, v) + gradoSalida(vertices, n, v) - ciclo;
}
