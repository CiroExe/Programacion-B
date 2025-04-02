#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void cargaVec(int [], int );
int sumaVec(int [], int);
void muestraVec(int [], int);
void muestraVecInverso(int [], int);


int main()
{
    int v[MAX], n;

    printf("Ingrese la cantidad de elementos del vector:\t");
    scanf("%d",&n);
    cargaVec(v,n);

    //Inciso i
    printf("Suma de elementos del vector cargado: %d\n", sumaVec(v,n-1));
    //Inciso ii
    muestraVecInverso(v, n-1);
    printf("\n");
    //Inciso iii
    muestraVec(v,n-1);


    return 0;
}

void cargaVec(int v[], int n)
{
    int i;

    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
}

int sumaVec(int v[], int n)
{
    if (n==0)
        return v[n];
    else
        return v[n]+sumaVec(v,n-1);
}

void muestraVecInverso(int v[], int n)
{
    if (n>-1)
    {
        printf("%d\t",v[n]);
        muestraVecInverso(v, n-1);
    }
}

void muestraVec(int v[],int n)
{
    if(n>-1)
    {
        muestraVec(v, n-1);
        printf("%d\t",v[n]);
    }
}
