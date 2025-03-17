#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void impares(int [], int);
void generaVec(int [], int, int, int[], int *);
void muestraVec(int [], int);
int main()
{
    int v[20],v2[20],i,j,N,x,k;
    char opcion;
    printf("INGRESE CANTIDAD DE ELEMNTOS DEL VECTOR\n");
    scanf("%d", &N);
    for (i=0;i<N;i++){
        printf("INGRESE DATO: \n");
        scanf("%d", &v[i]);
    }


    printf("INGRESE UNA OPCION -0 para finalizar-\n");
    do {

        scanf("%c",&opcion);
            switch (opcion){
                case '1':impares(v,N);
                         break;
                case '2':printf("INGRESE K: \n");
                         scanf("%d",&k);
                         generaVec(v,N,k,v2,&j);
                         muestraVec(v2,j);
                         break;
                case '3':printf("INGRESE ELEMENTO QUE DESEA BUSCAR\n");
                         scanf("%d",&x);
                         busca(v,N,x);
                         break;

            }


    }while(opcion != 0);


    return 0;
}


void impares(int v[], int N){
    int i;

    for (i=0; i<N; i++){
            if (v[i]%2 != 0)
                printf("%d  \n", v[i]);
    }
}

void generaVec(int v[], int N, int k, int v2[], int *j){
    int i;
    *j = 0;
    for (i=0;i<N;i++){
        if (v[i]%k == 0){
            v2[*j]= v[i];
            (*j)++;
        }
    }
}


void muestraVec(int v2[], int j){
    int i;
    for (i=0;i<j;i++){
        printf("%d  \n",v2[i]);
    }
}

int busca(int v[], int N, int x){

    int i = 0;

    while(i<N && v[i]!=x){
            i++;
    }

    if (i<N)
        printf("%d", i);
    else
        printf("NO SE ENCONTRO EL ELEMENTO. \n");

}
