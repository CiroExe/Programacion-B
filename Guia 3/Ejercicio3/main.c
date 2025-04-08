#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Dado un vector A de N elementos, obtener el promedio de sus elementos.

float promedio(int [], unsigned short int, unsigned short int);

int main()
{
    int A[MAX];
    unsigned short int i, n;

    printf("Ingrese cantidad de elementos del vector: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &A[i]);

    printf("El promedio de los elementos del vector A es %2.2f", promedio(A,n,n-1));


    return 0;
}


float promedio (int A[], unsigned short int n, unsigned short int i)
{
   if (i > 0)
        return (float)A[i]/n+promedio(A,n,i-1);
   else
        return (float)A[i]/n;

}
