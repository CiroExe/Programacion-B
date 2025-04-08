#include <stdio.h>
#include <stdlib.h>

// Determinar mediante una función “lógica” si una matriz cuadrada de dimensión NxN es simétrica (aij = aji) con respecto a su diagonal.
int esSimetrica(float [][20], int, int, int);
int main()
{
    int n, i, j;
    float mat[20][20];

    printf("Ingrese n \n");
    scanf("%d", &n);


    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%f", &mat[i][j]);

    if (esSimetrica(mat,n-2,n-1,n-1))
        printf("La matriz es simetrica");
    else
        printf("La matriz NO es simetrica");
    return 0;
}




int esSimetrica(float mat[][20], int i, int j, int n)
{
    if (j > 0)
        if (i > -1)
            if(mat[i][j]==mat[j][i])
                return esSimetrica(mat,i-1,j,n);
            else
                return 0;
        else
            return esSimetrica(mat, j-2, j-1, n);
    else
        return 1;





}
