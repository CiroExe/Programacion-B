#include <stdio.h>
#include <stdlib.h>


/**Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior)
**/


int gradoMatriz(int MA[MAX][MAX], unsigned int n, int v){
    unsigned int grado=0;

    for(j=0;j<n;j++){
        if (MA[v][j]!=0)
            if(v==j)
                grado+=2;
            else
                grado+=MA[v][j]; // 1 Si es arista o mas si es ponderado.
    }

    return grado;
}

int gradoLista(Grafo vec[], unsigned int n, int v){
    Tlista aux;
    unsigned int grado=0, i=busca(vec, n, v);

    aux=vec[i].nodosAdy;
    while(aux!=NULL){
        if(v==aux->dato)
            grado+=2;
        else
            grado++;
        aux=aux->sig;
    }

    return grado;
}

int gradoMatrizSup(int MA[MAX][MAX], unsigned int n, int v){
    unsigned int grado=0;
    //Para no tener que usar una funcion de busqueda voy a hacer coincidir el elemento con el indice de la matriz.

    for (j=v; j<n;j++) //Considerar la diagonal si hay un bucle
        if (MA[v][j]!=0)
            if (v==j)
                grado+=2;
            else
                grado++;

    return grado;
}
