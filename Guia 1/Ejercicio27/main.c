#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    unsigned int fila, columna;
    int valor;
} TVec;

void generaMat(int [MAX][MAX],unsigned *, unsigned *);
void generaV(TVec [], int [MAX][MAX], unsigned *, unsigned, unsigned);
void muestraV(TVec [], unsigned);

int main()
{
    TVec v[MAX];
    int mat[MAX][MAX];
    unsigned int n,m,k;

    generaMat(mat, &n, &m);
    generaV(v, mat, &k, n, m);
    muestraV(v, k);


    return 0;
}


void generaMat(int mat[MAX][MAX],unsigned *n, unsigned *m)
{
    int i, j;
    printf("Ingrese dimensiones de la matriz.\n");
    scanf("%d %d", n, m);

    for (i=0;i<*n;i++)
    {
        for(j=0;j<*m;j++)
        {
            printf("Ingrese elemento en la posicion %d %d\t", i, j);
            scanf("%d", mat[i][j]);
        }

    }

}

void generaV(TVec v[],int mat[MAX][MAX], unsigned *k, unsigned n, unsigned m)
{
    int i, j;
    int suma=n+m;
    *k=0;

    for( i=0;i<n;i++)
      for( j=0;j<m;j++)
        {
            if(mat[i][j]%suma==0)
            {
                v[*k].fila=i;
                v[*k].columna=j;
                v[*k].valor=mat[i][j];
                (*k)++;
            }

        }

}

void muestraV(TVec v[], unsigned k)
{
    int i;
    for(i=0;i<k;i++)
        printf("%d %d %d\n",v[i].fila, v[i].columna, v[i].valor);

}
