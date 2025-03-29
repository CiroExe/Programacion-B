#include <stdio.h>
#include <stdlib.h>
#define MAX 20
/*
Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él una cantidad desconocida de enteros (se encuentran en un archivo de texto). Posteriormente
a la carga, mostrar aquellos que sean positivos. Luego, para finalizar, liberar la memoria
solicitada en tiempo de ejecución.

*/

void cargaVec(int **, unsigned short int);
void muestraPositivos(int **, unsigned short int);
int main()
{
    int *v[MAX];
    unsigned short int n, i;


    printf("Ingrese n\n");
    scanf("%d",&n);

    cargaVec(v,n);
    muestraPositivos(v,n);

    for (i=0;i<n;i++)
        free(v[i]);
    return 0;
}

void cargaVec(int *v[], unsigned short int n)
{
    FILE *archt;
    unsigned short int i;
    int numero;


    archt=fopen("numeros.txt","r");
    if (archt==NULL)
        printf("No se pudo abrir el archivo");
    else
        {
                    for (i=0; i<n; i++)
                        {
                            v[i]=(int *)malloc(sizeof(int));
                            fscanf(archt,"%d", v[i]);
                        }


                fclose(archt);
        }
}

void muestraPositivos(int *v[], unsigned short int n)
{
    unsigned short int i;

    for (i=0; i<n ; i++)
    {
        if (*v[i]>0)
             printf("%d\n", *v[i]);
    }
}
