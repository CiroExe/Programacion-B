#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void generaMat(int [MAX][MAX], int *, int*);
void buscaPos(int [MAX][MAX], int, int, int);
float prom(int [MAX][MAX], int, int);
float promMat(int[MAX][MAX], int, int);
int buscaCero(int [MAX][MAX],int,int);
int cantSuperan(int [MAX][MAX], int, int, int);

int main()
{
    int mat[MAX][MAX],i,j,n,m,x;

    generaMat(mat,&n, &m);
    printf("Escriba el dato que desea buscar en la matriz \n");
    scanf("%d", &x);
    buscaPos(mat, n, m, x);

    for (j=0;j<m;j++)
        printf("El promedio de la columna %d es %2.2f\n", j, prom(mat,n,j));

    for (i=0;i<n;i++){
       if (buscaCero(mat,m,i)==1)
         printf("La cantidad de elementos que superan al promedio de la matriz en la fila %d fueron %d\n", i, cantSuperan(mat,n,m,i));
       else
         printf("No se encontro ningun 0 para la fila %d",i);



    }

    return 0;
}

void generaMat(int mat[MAX][MAX], int *n, int *m){
    int i,j;
    printf("Ingrese dimension de la matriz: \n");
    scanf("%d %d", n, m);

    for (i=0;i<*n;i++)
          for (j=0;j<*m;j++)
                scanf("%d", &mat[i][j]);

}
//  1 2 3
//  4 5 6  --> pos(4): [0][1]
//  7 8 9
void buscaPos(int mat[MAX][MAX], int n,int m, int x){
    int i=0, j=0;
    while (i<n && mat[i][j]!=x){
        while(j<m && mat[i][j]!=x){
           j++;
        }

        if (j==m){
            j=0;
            i++;
        }

    }

    if (i!=-1)
        printf("%d se encuentra en la posicion %d %d \n",x ,i, j);
    else
        printf("No se encontro %d \n", x);
}

float prom(int mat[MAX][MAX], int n,int col){
    int i=0,acum=0;
    for (i=0;i<n; i++)
       acum+=mat[i][col];

    return acum / n;
}

float promMat(int mat[MAX][MAX], int m, int n){
    int j=0, acumCol=0;


    for (j=0;j<m;j++)
        acumCol+=prom(mat, n, j);

    return acumCol / m;
}

int buscaCero(int mat[MAX][MAX], int m, int fila){
    int j=0, encuentraCero=0;

    while (j<m && encuentraCero==0){
        if (mat[fila][j]=0){
            encuentraCero=1;
            j++;
        }
    }

    return encuentraCero;
}

int cantSuperan(int mat[MAX][MAX],int n,int m, int fila){
    int i, cont=0;
    float promedio=promMat(mat,m,n);

    for(i=0;i<n;i++){
        if (mat[fila][i]>promedio)
            cont+=1;

    }

    return cont;
}




