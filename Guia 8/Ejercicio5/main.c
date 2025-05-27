#include <stdio.h>
#include <stdlib.h>
#define MAX 256

/* Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice  */

void cargaMat(unsigned short int [MAX][MAX],unsigned short int);
int gradoEntrada(unsigned short int [MAX][MAX], unsigned short int,unsigned int);
int gradoSalida(unsigned short int [MAX][MAX], unsigned short int,unsigned int);
int gradoVertice(unsigned short int [MAX][MAX], unsigned short int,unsigned int);

int main()
{
    unsigned int v;
    unsigned short int n ,MA[MAX][MAX];

    printf("INGRESE CANTIDAD DE ELEMENTOS DE LA MATRIZ DE ADYACENCIA:\t");
    scanf("%hu", &n);
    printf("\n");

    cargaMat(MA,n);


    printf("Ingrese vertice a analizar:\t");
    scanf("%u", &v);
    printf("\n");
    //Inciso A
    printf("Grado de Entrada para el vertice %u: %d\n", v, gradoEntrada(MA, n,v));

    //Inciso B
    printf("Grado de Salida para el vertice %u: %d\n",v, gradoSalida(MA,n, v));

    //Inciso C
    printf("Grado para el vertice %u: %d\n", v, gradoVertice(MA,n, v));

    return 0;
}

void cargaMat(unsigned short int mat[MAX][MAX], unsigned short int n){
    unsigned int i,j;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            printf("Ingrese elemento en la posicion [%hu][%hu]\t",i,j);
            scanf("%hu", &mat[i][j]);
            printf("\n");
        }
}

int gradoEntrada(unsigned short int mat[MAX][MAX], unsigned short int n,unsigned int v){
    unsigned int i, cont=0;

    for(i=0;i<n;i++)
        if(mat[i][v] == 1)
            cont++;

    return cont;
}

int gradoSalida(unsigned short int mat[MAX][MAX], unsigned short int n,unsigned int v){
    unsigned int j, cont=0;

    for(j=0;j<n;j++)
        if(mat[v][j] == 1)
            cont++;

    return cont;
}

int gradoVertice(unsigned short int mat[MAX][MAX], unsigned short int n,unsigned int v){
    return gradoEntrada(mat,n,v)+gradoSalida(mat, n,v)-(mat[v][v] != 0);
}


