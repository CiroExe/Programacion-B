#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void cargaMat(int [][MAX], int);
int min(int [][MAX], int, int ,int);

int main()
{
    int mat[MAX][MAX], n;

    printf("Ingrese cantidad de elementos de la matriz N X N\t");
    scanf("%d", &n);

    cargaMat(mat, n);

    printf("El elemento minimo de la matriz es %d", min(mat,n,n,n));
    return 0;
}

void cargaMat(int mat[][MAX],int n)
{
    int i,j;

    for(i=0;i<n;i++)
        for (j=0;j<n;j++)
            scanf("%d", &mat[i][j]);
}

int min(int mat[][MAX],int i, int j, int n)
{
    int minimo;
    if (j == -1)
        return 999;
    else
    {
        if (i > -1)
            if (mat[i][j] < min(mat, i-1, j, n))
                return mat[i][j];
            else
                return min(mat, i-1, j, n);
        else
            return min(mat,n,j-1,n);

    }

}
