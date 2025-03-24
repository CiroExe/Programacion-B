#include <stdio.h>
#include <stdlib.h>

void llenaVec(float **, int);
void muestraPositivos(float *, int);

int main()
{
    int n;
    float *v;

    printf("Ingrese cantidad de elementos del vector \n");
    scanf("%d", &n);

  //  v=(float *)malloc(n*sizeof(float));
    llenaVec(&v,n);
    muestraPositivos(v,n);


    free(v);
    return 0;
}

void llenaVec(float **var, int n)
{
    int i;

    *var=(float *)malloc(n*sizeof(float));

    for(i=0;i<n;i++)
        scanf("%f", *var+i);

}


/*void llenaVec(float *v, int n)
{
    int i;

    for(i=0;i<n;i++)
        scanf("%f", v+i);

}*/

void muestraPositivos(float *v, int n)
{
    int i;

    for(i=0;i<n;i++)
        if(*(v+i) > 0){
            printf("%.2f\t", *(v+i));
        }


}
