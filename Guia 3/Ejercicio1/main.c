#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int producto(int, int);
void division(int, int, int);
void cargaVec(int [], int);
int max(int [], int);
int main()
{
    int a, n, b, c, d, contador=0, v[MAX];
    printf("Ingrese la cantidad de elementos del vector: \n");
    scanf("%d",&n);
    cargaVec(v, n);
    printf("Ingrese a y b\n");
    scanf("%d %d", &a, &b);
    printf("El producto es: %d\n", producto(a,b));
    printf("Ingrese c y d\n");
    scanf("%d %d", &c, &d);
    division(c, d, 0);
    printf("El maximo del vector cargado es: %d", max(v,n));
    return 0;
}

void cargaVec(int v[MAX],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       scanf("%d",&v[i]);
    }

}

int max(int v[], int n)
{
    int maximo;
    if (n==0)
      return v[n];
    else
    {
        maximo=max(v,n-1);
        if (v[n]>maximo)
            return v[n];
        else
            return maximo;

    }
}

int producto(int x, int y)
{
    if (y==1)
        return x;
    else
        return x+(producto (x, y-1));

}

void division(int x, int y, int contador)
{
    if (x>1)
    {
        division(x-y,y,contador+1);
    }
    else
        if (x==1)
            printf("El resto es 1 y el cociente es:%d\n",contador);
        else
            printf("El resto es 0 y el cociente es:%d\n", contador);
}



