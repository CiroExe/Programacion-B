#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#define MAX 100


typedef int Grafo[MAX][MAX];

void BuscaAdyNoVisitado(Grafo, TPila *, int [], unsigned int, unsigned int);
int TodosVisitados(int [], unsigned int);
void muestraProfundidad(Grafo, unsigned int);
void BuscaAdys(Grafo, int, unsigned int, TCola *, int []);
void muestraAmplitud(Grafo, unsigned int);
int buscaSinVisitar(int [], unsigned int);


int main()
{
    int VV[MAX];
    unsigned int n=8;
    Grafo MA={
        {0,1,0,1,0,0,0,0},
        {1,0,1,0,1,1,0,0},
        {0,1,0,1,0,0,0,0},
        {1,0,1,0,0,0,0,1},
        {0,1,0,0,0,0,1,1},
        {0,1,0,0,0,0,1,0},
        {0,0,0,0,1,1,0,1},
        {0,0,0,1,1,0,1,0}
    };
    mostrarMatriz(MA, n);
    muestraProfundidad(MA,n);
    printf("\n");
    muestraAmplitud(MA, n);
    return 0;
}
void mostrarMatriz(Grafo MA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",MA[i][j]);
        }
        printf("\n");
    }
}

//Inciso A
void muestraProfundidad(Grafo MA, unsigned int n){
    TPila P;
    int vertice, CCC=0;
    int j, VV[MAX];

    for(int i=0;i<n;i++)
        VV[i]=0;


    printf("Ingrese vertice por el que quiere empezar\n");
    scanf("%d", &vertice);
    poneP(&P, vertice);

    while(!TodosVisitados(VV,n)){
        CCC++;
        if(VaciaP(P))
            poneP(&P, buscaSinVisitar(VV,n));
        else{
            while(!VaciaP(P) && !TodosVisitados(VV, n)){
                vertice=consultaP(P);
                if(!VV[vertice]){
                    VV[vertice]=1;
                    printf("%c ", vertice+65);
                }
                j=0;
                int encuentra=0;
                j = 0;
                while (j < n && !(MA[vertice][j] && !VV[j])) //MA[vertice][j] == 0 || VV[j] == 1 mientras no hay conexion o ya fue visitado sigo buscando
                    j++;

                if (j < n)
                    poneP(&P, j);  // j es el adyacente válido
                else
                    sacaP(&P, &vertice);
            }
        }
    }
    printf("\n");
    printf("Cantidad de grafos conexos:%d\n", CCC);
}

int buscaSinVisitar(int VV[], unsigned int n){
    for (unsigned int i = 0; i < n; i++)
        if (!VV[i])
            return i;
    return -1;
}

int TodosVisitados(int VV[], unsigned int n){
    int i = 0;
    while (i < n && VV[i])
        i++;
    return i == n;
}
void BuscaAdys(Grafo MA, int vertice,unsigned int n, TCola *C, int VV[]){

    for (int j=0;j<n;j++)
        if(MA[vertice][j] && !VV[j]){
            poneC(C, j);
            VV[j]=1;
            printf("%c ", j+65);
        }
}
//Inciso B
void muestraAmplitud(Grafo MA, unsigned int n){
    int vertice, CCC=0, VV[MAX];
    TCola C;
    iniciaC(&C);

    for(int i=0;i<n;i++)
        VV[i]=0;


    printf("Ingrese vertice por el que desea empezar\n");
    scanf("%d", &vertice);
    poneC(&C, vertice);
    VV[vertice]=1;
    printf("%c ",vertice+65);

    while(!TodosVisitados(VV, n)){
        CCC++;
        if(VaciaC(C))
           poneC(&C, buscaSinVisitar(VV,n));
        else{
            while(!VaciaC(C) && !TodosVisitados(VV, n)){
                sacaC(&C, &vertice);
                BuscaAdys(MA,vertice,n,&C,VV);
            }
        }
    }
    printf("\n");
    printf("Cantidad de grafos conexos: %d\n", CCC);
}

