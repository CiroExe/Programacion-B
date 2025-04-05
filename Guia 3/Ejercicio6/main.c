#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par. */

int cumpleFila(int [][MAX], int, int, int, int, int, int);

int main()
{
    int mat[MAX][MAX],n, m, i, j;

    printf("Ingrese n y m\n");
    scanf("%d %d", &n, &m);

    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%d", &mat[i][j]);

    printf(cumpleFila(mat,0,0,n-1,m-1,0,0) ? "Cumple" : "No cumple");




    return 0;
}


int cumpleFila(int mat[][MAX], int i, int j, int n, int m, int ant, int act)
{
    if (i > n) //Recorrió toda la matriz
        return 1;
    else
        if (j > m)
            if (i == 0 && act % 2 == 0 || i > 0 && act > ant) //Si recorrió todas las columnas analizar las condiciones en caso de estar en la primera fila u otra distinta.
                return cumpleFila(mat, i+1, 0, n, m, act, 0);
            else
                return 0;
        else
            return cumpleFila(mat, i, j+1, n, m, ant, act+mat[i][j]);
}
