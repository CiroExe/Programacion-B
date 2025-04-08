#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//Dada una matriz A de NxM float, retornar la cantidad de veces que un valor X aparece en A  (realizar una versión void y otra int)

int contX(float [][MAX], float, unsigned short int, unsigned short, unsigned short, unsigned short);
void contaX(float [][MAX], float, unsigned short int, unsigned short int, unsigned short int, unsigned short int, int);

int main()
{
    unsigned short int n, m, i, j;
    float mat[20][20], X;

    printf("Ingrese n y m \n");
    scanf("%hu %hu", &n, &m);


    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            scanf("%f", &mat[i][j]);

    printf("Ingrese valor a buscar X\t");
    scanf("%f", &X);

    printf("La cantidad de veces que aparece X en la matriz es %d veces\n", contX(mat,X,0,0,n-1,m-1));
    contaX(mat, X, 0, 0, n-1, m-1, 0);


    return 0;
}

int contX(float mat[][MAX], float X, unsigned short int i, unsigned short int j, unsigned short int n, unsigned short int m)
{
    if (i > n)
        return 0;
    else
        if (j > m)
            return contX(mat, X, i+1, 0, n, m);
        else
            if (mat[i][j] == X)
                return 1 + contX(mat, X, i, j+1, n, m);
            else
                return contX(mat, X, i, j+1, n, m);
}

void contaX(float mat[][MAX], float X, unsigned short int i, unsigned short int j, unsigned short int n, unsigned short int m, int cont)
{
    if (i > n)
        printf("La cantidad de veces que aparece X en la matriz es %d veces\n", cont);
    else
        if (j > m)
            contaX(mat, X, i+1, 0, n, m, cont);
        else
            if (mat[i][j] == X)
                contaX(mat, X, i, j+1, n, m, cont+1);
            else
                contaX(mat,X, i , j+1, n, m, cont);
}


