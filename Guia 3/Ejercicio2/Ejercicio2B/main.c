#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void cargaVec(float [],int);
int busquedaLineal(float [], float,int);
int busquedaBinaria(float [], float, int, int);

int main()
{
    float v[MAX], x;
    int n,pos,posBinario;

    printf("Ingrese la cantidad de elementos del vector:\t");
    scanf("%d", &n);

    printf("Ingrese valor de X:\t");
    scanf("%f", &x);

    cargaVec(v, n);

    //Inciso i

    pos=busquedaLineal(v,x,n-1);

    if (posBinario == -1)
        printf("No se encontro el elemento\n");
    else
        printf("El elemento %.2f se encontro en la posicion %d\n",x,pos);

    //Inciso ii

    posBinario=busquedaBinaria(v,x,0,n-1);

    if (posBinario == -1)
        printf("No se encontro el elemento\n");
    else
        printf("El elemento %.2f se encontro en la posicion %d\n",x,posBinario);
    return 0;
}


void cargaVec(float v[],int n)
{
    int i;

    for (i=0;i<n;i++)
        scanf("%f", &v[i]);
}
int busquedaLineal(float v[], float x,int n)
{
    if (n<0)
        return -1;
    else
        if (v[n]==x)
            return n;
        else
            return busquedaLineal(v,x,n-1);
}

int busquedaBinaria(float v[], float x, int pri, int ult)
{
    int medio = (pri + ult) / 2;
    if (pri > ult)
        return -1;
    else
    {
        if (x == v[medio])
            return medio;
        else
            if (x < v[medio])
                return busquedaBinaria(v, x, pri, medio - 1);
            else
                return busquedaBinaria(v, x, medio + 1, ult);
    }
}



