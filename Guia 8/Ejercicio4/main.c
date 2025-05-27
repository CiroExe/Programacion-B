#include <stdio.h>
#include <stdlib.h>
#define MAX 256

//Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
//representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente.

void muestraMat(int [MAX][MAX]);
void retornaSubyacente(int [MAX][MAX]);
int main()
{
    int MA[MAX][MAX], i, j;
    for (i=0; i<4; i++)
        for (j=0;j<4;j++)
            scanf("%d",&MA[i][j]);
    muestraMat(MA);
    printf("\n\n");
    retornaSubyacente(MA);
    muestraMat(MA);


    return 0;
}

void muestraMat(int Mat[MAX][MAX]){
    unsigned int i, j;

    for (i=0;i<4;i++){
        for (j=0;j<4; j++)
            printf("%d\t", Mat[i][j]);
        printf("\n");
    }
}

void retornaSubyacente(int Mat[MAX][MAX]){
    unsigned int i,j;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if (Mat[i][j] == 1)
                Mat[j][i]=1;
}
